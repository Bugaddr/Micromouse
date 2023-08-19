# Micromouse

This repository contains the code, design, and documentation for a micromouse robot. The robot is based on the Arduino Uno and uses ultrasonic sensors to navigate through the maze.

## Component List

| Name                        | Quantity |
| --------------------------- | -------- |
| Arduino Uno R3              | 1        |
| Ultrasonic Distance Sensor  | 4        |
| DC Motor                    | 2        |
| Piezo buzzer                | 1        |
| H-bridge Motor Driver L293D | 1        |

**NOTE:** Wheels and chassie are also required for finalization

## Algorithm

This micromouse is based on the [LSRB algorithm](<[https://en.wikipedia.org/wiki/LSRB_algorithm](https://www.hackster.io/Varun2905/maze-solving-robot-3-ir-sensors-9ada3b#toc---34-lsrb--34--algorithm-2)>), which is a simple but effective algorithm for solving mazes. It works by moving the robot forward until it detects a wall. When the robot detects a wall, it turns left, right, or back depending on the following rules based on priority:

1. Always follow **LEFT** whenever a turn is possible.
2. If _LEFT_ is not possible go **STRAIGHT**.
3. If _LEFT_ and _STRAIGHT_ both are not possible go **RIGHT**.
4. If _LEFT_, _STRAIGHT_, and _RIGHT_ are not possible go **BACK** (or it means take a U-turn).

Our approach for solving different conditions are:

1. **Simple or Straight lane:** The robot will follow the straight path.
2. **Left Turn (left only):** The robot will take a left turn.
3. **Right Turn (right only):** The robot will take a right turn.
4. **T intersection (T):** The robot will take a left turn.
5. **Left T Intersection (straight or left):** The robot will take a left turn.
6. **Right T Intersection (straight or right):** The robot will take a left turn.
7. **Dead End:** The robot will take a U-turn.
8. **Four lane intersection (Cross):** The robot will go little further, if sensors still give same output then its end of maze else it will go left
9. **End of Maze:** The robot will stop.

![image](https://github.com/Bugaddr/micromouse/assets/75427894/a526c429-3939-4612-92c3-594908534565)

**NOTE:** Checkout our implemented code [here](https://github.com/Bugaddr/micromouse/blob/main/main.ino)

## Tinkercad design & circuit diagram

- Checkout [circuit diagram pdf](https://github.com/Bugaddr/micromouse/blob/main/circuit.pdf)
- Checkout [tinkercad circuit design](https://www.tinkercad.com/things/jYmtUu4jmhq-micromousev1)

[![Tinkercad design](https://github.com/Bugaddr/micromouse/assets/75427894/1b375f9f-6475-4405-87c7-a5234094cdfe)](https://github.com/Bugaddr/micromouse/blob/main/assets/75427894/1b375f9f-6475-4405-87c7-a5234094cdfe)

## Reference
1. [How to Build an Arduino-based Maze-Solving Robot](https://maker.pro/arduino/projects/how-to-build-an-arduino-based-maze-solving-robot)
2. [Maze-Solving Algorithm](https://en.wikipedia.org/wiki/Maze-solving_algorithm)
3. [Maze Generation Algorithm](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
4. [Maze-Solving Robot with 3 IR Sensors](https://www.hackster.io/Varun2905/maze-solving-robot-3-ir-sensors-9ada3b)
5. [Coding a Line-Follower Robot using LSRB and Finding the Shortest Path](https://towardinfinity.medium.com/coding-a-line-follower-robot-using-lsrb-and-finding-the-shortest-path-d906ffec71d)

## Special thanks
1. [RCOEM](https://rknec.edu/) Robotics & Aviation club

## Contributing
This project is open source and we welcome contributions from everyone. If you have any suggestions or improvements, please feel free to open an issue or submit a pull request.

- Thank you for your interest in micromouse !
- I hope this helps !
