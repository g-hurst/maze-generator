# maze-generator

### How to run:
**option 1:**
1. run `make`
   * creates the executable
2.  run `generate_maze.exe [rows] [columns]`
* rows is the amount of rows the generated maze will contain
  * cols is the amount of columns the generated maze will contain
  * defaults to 25 if not specified

**option 2:**
1. run `make run ROWS=[rows] COLS=[columns]`
   * rows is the amount of rows the generated maze will contain
   * cols is the amount of columns the generated maze will contain
   * defaults to 25 if not specified

### Requirements to run this code:
* maze rows and columns must be greater than three units
* maze rows and columns must be odd numbers
* if either of these is not met, a terminal message will prompt for an input to replace the invalid size

### Algorithm:

The algorithm used to generate the maze is a variation of the Hunt and Kill algorithm. The difference in this generator is that instead of looping through the individual searches and path generations, path generations are recursivly called within the walk funciton. 

1. start at a random room and mark it as visited
2. randomly select an adjacent, unvisited, in bounds room
3. advance to the selected room and mark it as visited
4. remove the wall between the previous and current room
5. repeat steps 2 - 4 until all adjacent rooms have been visited or are out of bounds
6. traverse the maze room by room checking for an unvisted room with an adjacent visited room
   * if found, recall steps 2-5 starting at the visited room
   * if none are found, end
