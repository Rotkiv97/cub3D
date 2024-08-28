# Cub3D

![clip](./docs/clip/Cub3D.gif)


## Overview
cub3D is a project inspired by the iconic Wolfenstein 3D game, aiming to implement a 3D graphical representation of a maze using ray-casting principles. Developed in C, it utilizes the miniLibX library for graphics rendering. The goal is to create an immersive first-person perspective experience where users navigate through a maze while interacting with different elements.

# [Subject](./Cub3D.subject.pdf)


## Installation
To run cub3D, follow these steps:
1. Clone the repository: 
```bash
git clone https://github.com/Rotkiv97/cub3D.git
```
2. Navigate to the project directory: `cd cub3D`
3. Extract and compile with `make` the minilibx-linux.tgz archive, command to install minilibx library dependencies  `sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`
4. Compile the project using the provided Makefile: `make` in the root of the project
5. Run the executable with a map file as an argument: `./cub3D <map-file.cub>`

## Usage
Once installed, cub3D can be executed with the following command:
- Replace `<map-file.cub>` with the path to your scene description file in the specified format.
- Use the arrow keys to look left and right in the maze.
- Use the W, A, S, and D keys to move the point of view through the maze.
- Press ESC to close the window and quit the program cleanly.
- Click on the red cross on the window’s frame to close the window and quit the program cleanly.

Note: Ensure that your map file adheres to the specified format and contains valid scene information.

### Authors
- [dcolucci](https://github.com/Coluyanson)
- [vguidoni](https://github.com/Rotkiv97)
