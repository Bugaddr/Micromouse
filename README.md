# Micromouse

This repository contains the code, design, and documentation for a micromouse robot. The robot is based on the Arduino Uno and uses ultrasonic sensors to navigate through the maze.

## Component List

| Name                        | Quantity |
| --------------------------- | -------- |
| Arduino Uno R3              | 1        |
| Ultrasonic Distance Sensor  | 4        |
| DC Motor                    | 2        |
| Piezo                       | 1        |
| H-bridge Motor Driver L293D | 1        |

## Algorithm

This micromouse is based on the [LSRB algorithm]([https://en.wikipedia.org/wiki/LSRB_algorithm](https://www.hackster.io/Varun2905/maze-solving-robot-3-ir-sensors-9ada3b#toc---34-lsrb--34--algorithm-2)), which is a simple but effective algorithm for solving mazes. It works by moving the robot forward until it detects a wall. When the robot detects a wall, it turns left, right, or back depending on the following rules:

1. **Simple or Straight lane:** The robot will follow the straight path.
2. **Left Turn (left only):** The robot will take a left turn.
3. **Right Turn (right only):** The robot will take a right turn.
4. **T intersection (T):** The robot will take a left turn.
5. **Left T Intersection (straight or left):** The robot will take a left turn.
6. **Right T Intersection (straight or right):** The robot will take a left turn.
7. **Dead End:** The robot will take a U-turn.
8. **Four lane intersection (Cross):** The robot will take a left turn.
9. **End of Maze:** The robot will stop.

![image](https://github.com/Bugaddr/micromouse/assets/75427894/a526c429-3939-4612-92c3-594908534565)

## Tinkercad design

[![Tinkercad design](https://github.com/Bugaddr/micromouse/assets/75427894/1b375f9f-6475-4405-87c7-a5234094cdfe)](https://github.com/Bugaddr/micromouse/blob/main/assets/75427894/1b375f9f-6475-4405-87c7-a5234094cdfe)

## Circuit diagram

Checkout [circuit diagram](https://github.com/Bugaddr/micromouse/blob/main/circuit.pdf) pdf
