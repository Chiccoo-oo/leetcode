import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Range
from std_msgs.msg import String
import time
import random

class MazeSolver(Node):
    def __init__(self):
        super().__init__('maze_solver')

        # Publisher for velocity commands
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Subscribers for ultrasonic sensors
        self.create_subscription(Range, '/front_ultrasonic_sensor_range', self.front_sensor_callback, 10)
        self.create_subscription(Range, '/left_ultrasonic_sensor_range', self.left_sensor_callback, 10)
        self.create_subscription(Range, '/right_ultrasonic_sensor_range', self.right_sensor_callback, 10)
        self.create_subscription(Range, '/rear_ultrasonic_sensor_range', self.rear_sensor_callback, 10)

        # Subscribe to robot's area information
        self.create_subscription(String, '/robot_area', self.area_callback, 10)

        # Sensor data initialization
        self.front_distance = float('inf')
        self.left_distance = float('inf')
        self.right_distance = float('inf')
        self.rear_distance = float('inf')
        self.current_area = None
        self.last_sensor_update = time.time()

        # Timer for control loop
        self.timer = self.create_timer(0.05, self.control_loop)  # 20 Hz update rate

        # Recovery state
        self.recovery_mode = False
        self.recovery_timer = time.time()

        # Flag for the goal reached state
        self.goal_reached = False

    def front_sensor_callback(self, msg):
        self.front_distance = msg.range
        self.last_sensor_update = time.time()

    def left_sensor_callback(self, msg):
        self.left_distance = msg.range
        self.last_sensor_update = time.time()

    def right_sensor_callback(self, msg):
        self.right_distance = msg.range
        self.last_sensor_update = time.time()

    def rear_sensor_callback(self, msg):
        self.rear_distance = msg.range
        self.last_sensor_update = time.time()



    def area_callback(self, msg):
        self.current_area = msg.data
        self.get_logger().info(f"Current area: {self.current_area}")

    def recovery_behavior(self, twist_msg):
        """Recovery behavior to escape stuck positions."""
        # Move backward for a brief period (0.5 seconds)
        twist_msg.linear.x = -0.1  # Move backward slowly
        twist_msg.angular.z = 0.0  # No turning while moving backward
        self.cmd_vel_pub.publish(twist_msg)

        # Wait a brief moment, then re-evaluate the situation
        time.sleep(0.5)

        # After moving backward, try a random turn to find a new path
        twist_msg.linear.x = 0.0  # Stop moving backward
        twist_msg.angular.z = random.uniform(-1.0, 1.0)  # Random turn
        self.cmd_vel_pub.publish(twist_msg)
        time.sleep(0.5)  # Give it time to turn and try to detect the new path

    def control_loop(self):
        twist_msg = Twist()

        # Ensure sensors are providing valid data
        if time.time() - self.last_sensor_update > 1.0:  # Timeout for sensor data
            self.get_logger().warn("Waiting for valid sensor data...")
            return

        # Check if the robot has reached Area 3 (goal position)
        if self.current_area == "3" and not self.goal_reached:
            self.get_logger().info("Robot has reached the goal (Area 3), starting return journey.")
            self.goal_reached = True  # Mark goal as reached
            self.return_to_start(twist_msg)
            return

        # Check if the robot is back at Area 1 (start position)
        if self.current_area == "1" and self.goal_reached:
            self.get_logger().info("Robot has returned to the start position (Area 1), ready to learn again.")
            self.goal_reached = False  # Reset goal reached flag for learning again
            # Optionally, you can reset the robot's learned path here if needed
            self.start_learning_phase(twist_msg)
            return

        if self.current_area == "1" and self.front_distance < 0.5:
            self.get_logger().info("Robot is back at the start position (Area 1), stopping.")
            twist_msg.linear.x = 0.0  # Stop the robot
            twist_msg.angular.z = 0.0
            self.cmd_vel_pub.publish(twist_msg)
            return

        # Regular maze-solving logic (same as before)
        ideal_distance = 0.4  # Ideal distance from the wall (in meters)
        max_distance = 0.6  # Max distance before getting too far from the wall
        min_distance = 0.2  # Min distance before the robot is too close to the wall

        # Proportional control for front sensor (distance to wall in front)
        if self.front_distance < min_distance:
            # Stop if too close to the front wall
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 0.0
            self.cmd_vel_pub.publish(twist_msg)

            # Compare left and right distances and choose direction
            if self.left_distance > self.right_distance:
                # Turn left 90 degrees if there's more space on the left
                twist_msg.angular.z = 1.0  # Turn left at a moderate speed
                self.cmd_vel_pub.publish(twist_msg)
                time.sleep(1.5)  # Wait for 90-degree turn
                twist_msg.angular.z = 0.0  # Stop turning after completing the 90-degree turn
                self.cmd_vel_pub.publish(twist_msg)

                # Move forward in the new direction
                twist_msg.linear.x = 0.3  # Move forward at a moderate speed
                self.cmd_vel_pub.publish(twist_msg)
                time.sleep(2.0)  # Move forward for a while until the next wall is encountered
            else:
                # Turn right 90 degrees if there's more space on the right
                twist_msg.angular.z = -1.0  # Turn right at a moderate speed
                self.cmd_vel_pub.publish(twist_msg)
                time.sleep(1.5)  # Wait for 90-degree turn
                twist_msg.angular.z = 0.0  # Stop turning after completing the 90-degree turn
                self.cmd_vel_pub.publish(twist_msg)

                # Move forward in the new direction
                twist_msg.linear.x = 0.3  # Move forward at a moderate speed
                self.cmd_vel_pub.publish(twist_msg)
                time.sleep(2.0)  # Move forward for a while until the next wall is encountered

            return

        # Regular proportional control for left and right distances
        if self.left_distance < min_distance:
            twist_msg.linear.x = 0.1  # Move slowly to avoid wall
            twist_msg.angular.z = 0.3  # Turn right to balance
            self.cmd_vel_pub.publish(twist_msg)

        elif self.right_distance < min_distance:
            twist_msg.linear.x = 0.1  # Move slowly to avoid wall
            twist_msg.angular.z = -0.3  # Turn left to balance
            self.cmd_vel_pub.publish(twist_msg)

        elif min_distance <= self.left_distance <= max_distance and min_distance <= self.right_distance <= max_distance:
            left_diff = self.left_distance - ideal_distance
            right_diff = self.right_distance - ideal_distance
            twist_msg.linear.x = 0.3  # Default forward speed
            twist_msg.angular.z = (left_diff - right_diff) * 0.5  # Adjust turning to keep balance
            self.cmd_vel_pub.publish(twist_msg)

        # If stuck, move backward and try again
        stuck_threshold = 0.2  # Robot is considered stuck if the left distance is too small
        if self.left_distance < stuck_threshold:
            self.recovery_mode = True

        if self.recovery_mode:
            self.recovery_behavior(twist_msg)
            self.recovery_mode = False  # Reset recovery mode after handling
            return

        twist_msg.linear.x = 0.3  # Move forward at a moderate speed
        twist_msg.angular.z = 0.0  # Maintain straight path
        self.cmd_vel_pub.publish(twist_msg)

    def return_to_start(self, twist_msg):
        """Moves the robot back to the starting position."""
        # Reverse direction and return to Area 1
        twist_msg.linear.x = -0.3  # Move backward
        twist_msg.angular.z = 0.0  # Move straight
        self.cmd_vel_pub.publish(twist_msg)
        time.sleep(2.0)  # Move for a while to reach the starting area
        twist_msg.linear.x = 0.0  # Stop the robot
        self.cmd_vel_pub.publish(twist_msg)

    def start_learning_phase(self, twist_msg):
        """Start learning phase to go towards Area 3."""
        # Set up robot to learn and solve the maze again
        twist_msg.linear.x = 0.3  # Move forward
        twist_msg.angular.z = 0.0  # Go straight
        self.cmd_vel_pub.publish(twist_msg)

def main(args=None):
    rclpy.init(args=args)
    maze_solver = MazeSolver()
    rclpy.spin(maze_solver)
    maze_solver.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
