#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Range
from std_msgs.msg import String
from collections import deque

# Directions for BFS movement
# Up, Down, Left, Right (row, col)
MOVES = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Corresponding to up, down, left, right

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

        # Maze grid representation (for simulation purposes, change this to your actual grid)
        self.grid = [
            [0, 0, 1, 0, 0],  # 0 = free, 1 = wall
            [1, 0, 1, 1, 0],
            [1, 0, 0, 1, 0],
            [0, 1, 0, 0, 0],
            [0, 0, 0, 1, 0]
        ]
        
        self.rows = len(self.grid)
        self.cols = len(self.grid[0])

        # Area tracking
        self.current_area = None

        # BFS tracking
        self.visited = set()  # Visited positions in the grid
        self.queue = deque()  # Queue for BFS, stores (row, col) and path

        # Start position (could be modified based on actual start)
        self.start = (0, 0)  # Starting at top-left corner
        self.goal = (4, 4)   # Goal position (bottom-right corner)

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

        # BFS movement logic
        # Get possible directions based on sensor readings (front, left, right, rear)
        directions = self.get_possible_moves()

        if directions:
            # Move in the first available direction
            direction = directions[0]
            twist_msg.linear.x = 0.5 if direction in [(1, 0), (-1, 0)] else 0.0  # Move forward/backward
            twist_msg.angular.z = 1.0 if direction == (0, -1) else -1.0 if direction == (0, 1) else 0.0
            self.get_logger().info(f"Moving in direction: {direction}")
        else:
            # If no possible moves, stop
            twist_msg.linear.x = 0.0
            twist_msg.angular.z = 0.0
            self.get_logger().info("No moves available, stopping.")

        # Publish movement command
        self.cmd_vel_pub.publish(twist_msg)

    def get_possible_moves(self):
        """
        Get all possible directions the robot can move based on the sensor readings
        and the current position in the maze.
        """
        possible_moves = []
        if self.front_distance > 0.5 and self.is_free(self.start[0] - 1, self.start[1]):  # Move Up
            possible_moves.append((-1, 0))
        if self.left_distance > 0.5 and self.is_free(self.start[0], self.start[1] - 1):  # Move Left
            possible_moves.append((0, -1))
        if self.right_distance > 0.5 and self.is_free(self.start[0], self.start[1] + 1):  # Move Right
            possible_moves.append((0, 1))
        if self.rear_distance > 0.5 and self.is_free(self.start[0] + 1, self.start[1]):  # Move Down
            possible_moves.append((1, 0))
        return possible_moves

    def is_free(self, row, col):
        """
        Check if a grid cell is free to move (i.e., not a wall).
        """
        if 0 <= row < self.rows and 0 <= col < self.cols:
            return self.grid[row][col] == 0  # 0 means free, 1 means wall
        return False

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
