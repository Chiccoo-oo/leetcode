#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Range
from std_msgs.msg import String
from collections import deque

class MazeSolverBFS(Node):

    def __init__(self):
        super().__init__('maze_solver_bfs')

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

        # BFS tracking
        self.visited = set()
        self.queue = deque()  # Queue for BFS, stores positions (row, col) and path

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

        # BFS movement logic
        if self.front_distance > 0.5:
            # Move forward if no obstacle
            self.add_to_queue('forward')
            twist_msg.linear.x = 0.5
            twist_msg.angular.z = 0.0
        elif self.left_distance > 0.5:
            # Turn left if left path is unvisited
            self.add_to_queue('left')
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 1.0
        elif self.right_distance > 0.5:
            # Turn right if right path is unvisited
            self.add_to_queue('right')
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = -1.0
        else:
            # Backtrack if no other unvisited paths
            if self.queue:
                self.backtrack()
            else:
                twist_msg.linear.x = 0.0
                twist_msg.angular.z = 0.0

        # Publish movement command
        self.cmd_vel_pub.publish(twist_msg)

    def add_to_queue(self, direction):
        """
        Adds the current position to the queue for BFS exploration.
        """
        current_position = (self.front_distance, self.left_distance, self.right_distance, self.rear_distance)
        if current_position not in self.visited:
            self.queue.append(current_position)
            self.visited.add(current_position)

    def backtrack(self):
        """
        Backtrack by popping from the queue.
        """
        if self.queue:
            last_position = self.queue.pop()
            self.get_logger().info(f"Backtracking to position: {last_position}")


def main(args=None):
    rclpy.init(args=args)
    node = MazeSolverBFS()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    # Shutdown
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
