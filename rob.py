# #!/usr/bin/env python3

# import rclpy
# from rclpy.node import Node
# from geometry_msgs.msg import Twist
# from sensor_msgs.msg import Range
# from std_msgs.msg import String  # To subscribe to the robot's area info

# class MazeSolver(Node):

#     def __init__(self):
#         super().__init__('maze_solver')
        
#         # Create a publisher for the cmd_vel topic
#         self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

#         # Create subscribers for the ultrasonic sensor topics
#         self.create_subscription(Range, '/front_ultrasonic_sensor_range', self.front_sensor_callback, 10)
#         self.create_subscription(Range, '/left_ultrasonic_sensor_range', self.left_sensor_callback, 10)
#         self.create_subscription(Range, '/right_ultrasonic_sensor_range', self.right_sensor_callback, 10)
#         self.create_subscription(Range, '/rear_ultrasonic_sensor_range', self.rear_sensor_callback, 10)

#         # Subscribe to the topic that publishes the current area
#         self.create_subscription(String, '/robot_area', self.area_callback, 10)

#         # Initialize sensor data
#         self.front_distance = float('inf')
#         self.left_distance = float('inf')
#         self.right_distance = float('inf')
#         self.rear_distance = float('inf')

#         # Initialize area data
#         self.current_area = None

#         # Define the movement control loop timer
#         self.timer = self.create_timer(0.05, self.control_loop)  # Run at 20 Hz

#     def front_sensor_callback(self, msg):
#         self.front_distance = msg.range

#     def left_sensor_callback(self, msg):
#         self.left_distance = msg.range

#     def right_sensor_callback(self, msg):
#         self.right_distance = msg.range

#     def rear_sensor_callback(self, msg):
#         self.rear_distance = msg.range

#     def area_callback(self, msg):
#         """Callback function to update the robot's current area."""
#         self.current_area = msg.data  # Update the area (should be "1", "2", or "3")
#         self.get_logger().info(f"Current area: {self.current_area}")

#     def control_loop(self):
#         """Control logic for navigating through the maze."""
#         twist_msg = Twist()

#         # Check if the robot has reached Area 3 or Area 1
#         if self.current_area == "3":
#             self.get_logger().info("Robot has reached the final position (Area 3), stopping.")
#             twist_msg.linear.x = 0.0  # Stop the robot
#             twist_msg.angular.z = 0.0
#             self.cmd_vel_pub.publish(twist_msg)
#             return

#         if self.current_area == "1" and self.front_distance < 0.5:
#             self.get_logger().info("Robot is back at the start position (Area 1), stopping.")
#             twist_msg.linear.x = 0.0  # Stop the robot
#             twist_msg.angular.z = 0.0
#             self.cmd_vel_pub.publish(twist_msg)
#             return

#         # Optimized movement logic for faster navigation
#         if self.front_distance < 0.3:
#             # Obstacle ahead, turn sharply based on side distances
#             if self.left_distance > self.right_distance:
#                 twist_msg.linear.x = 0.0
#                 twist_msg.angular.z = 1.0  # Sharper left turn
#             else:
#                 twist_msg.linear.x = 0.0
#                 twist_msg.angular.z = -1.0  # Sharper right turn
#         elif self.left_distance < 0.3:
#             # Too close to the left wall, turn right slightly
#             twist_msg.linear.x = 0.3  # Faster forward motion
#             twist_msg.angular.z = -0.3
#         elif self.right_distance < 0.3:
#             # Too close to the right wall, turn left slightly
#             twist_msg.linear.x = 0.3  # Faster forward motion
#             twist_msg.angular.z = 0.3
#         else:
#             # No obstacles nearby, move forward faster
#             twist_msg.linear.x = 0.5
#             twist_msg.angular.z = 0.0

#         # Publish the movement command
#         self.cmd_vel_pub.publish(twist_msg)

# def main(args=None):
#     rclpy.init(args=args)
#     node = MazeSolver()

#     try:
#         rclpy.spin(node)
#     except KeyboardInterrupt:
#         pass

#     # Shutdown the node
#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()


#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Range
from std_msgs.msg import String


class MazeSolverDFS(Node):

    def __init__(self):
        super().__init__('maze_solver_dfs')

        # Publishers and subscribers
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.create_subscription(Range, '/front_ultrasonic_sensor_range', self.front_sensor_callback, 10)
        self.create_subscription(Range, '/left_ultrasonic_sensor_range', self.left_sensor_callback, 10)
        self.create_subscription(Range, '/right_ultrasonic_sensor_range', self.right_sensor_callback, 10)
        self.create_subscription(Range, '/rear_ultrasonic_sensor_range', self.rear_sensor_callback, 10)
        self.create_subscription(String, '/robot_area', self.area_callback, 10)

        # Sensor data
        self.front_distance = float('inf')
        self.left_distance = float('inf')
        self.right_distance = float('inf')
        self.rear_distance = float('inf')

        # Area tracking
        self.current_area = None

        # DFS tracking
        self.visited = set()
        self.position_stack = []
        self.current_position = (0, 0)  # Starting position in the maze (grid-based)

        # Timer for control loop
        self.timer = self.create_timer(0.1, self.control_loop)

    def front_sensor_callback(self, msg):
        self.front_distance = msg.range

    def left_sensor_callback(self, msg):
        self.left_distance = msg.range

    def right_sensor_callback(self, msg):
        self.right_distance = msg.range

    def rear_sensor_callback(self, msg):
        self.rear_distance = msg.range

    def area_callback(self, msg):
        self.current_area = msg.data
        self.get_logger().info(f"Current area: {self.current_area}")

    def control_loop(self):
        twist_msg = Twist()

        # Stop the robot if Area 3 is reached
        if self.current_area == "3":
            self.get_logger().info("Robot has reached the final position (Area 3), stopping.")
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 0.0
            self.cmd_vel_pub.publish(twist_msg)
            return

        # Stop the robot if back at Area 1
        if self.current_area == "1" and self.front_distance < 0.5:
            self.get_logger().info("Robot is back at the start position (Area 1), stopping.")
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 0.0
            self.cmd_vel_pub.publish(twist_msg)
            return

        # DFS movement logic
        if self.front_distance > 0.5 and self.current_position not in self.visited:
            # Move forward if unvisited and no obstacle
            self.visited.add(self.current_position)
            twist_msg.linear.x = 0.5  # Increased forward speed
            twist_msg.angular.z = 0.0
            self.position_stack.append(self.current_position)
            self.current_position = (self.current_position[0] + 1, self.current_position[1])
        elif self.left_distance > 0.5 and (self.current_position[0] - 1, self.current_position[1]) not in self.visited:
            # Turn left if left path is unvisited
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 1.0  # Increased turn speed
            self.cmd_vel_pub.publish(twist_msg)
            self.visited.add((self.current_position[0] - 1, self.current_position[1]))
            self.current_position = (self.current_position[0] - 1, self.current_position[1])
        elif self.right_distance > 0.5 and (self.current_position[0], self.current_position[1] + 1) not in self.visited:
            # Turn right if right path is unvisited
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = -1.0  # Increased turn speed
            self.cmd_vel_pub.publish(twist_msg)
            self.visited.add((self.current_position[0], self.current_position[1] + 1))
            self.current_position = (self.current_position[0], self.current_position[1] + 1)
        elif self.position_stack:
            # Backtrack if no other unvisited paths
            back_position = self.position_stack.pop()
            twist_msg.linear.x = -0.5  # Increased backtracking speed
            twist_msg.angular.z = 0.0
            self.current_position = back_position
        else:
            # Stop if fully explored
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 0.0

        # Publish movement command
        self.cmd_vel_pub.publish(twist_msg)


def main(args=None):
    rclpy.init(args=args)
    node = MazeSolverDFS()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    # Shutdown
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
