# maze-generator

### How to run:

### Requirements to run this code:
* maze rows and columns must be greater than three units
* maze rows and columns must be odd numbers
* if either of these is not met, a terminal message will prompt for an input to replace the invalid size


The algorithm used to generate the maze is a variation of the Hunt and Kill algorithm. The difference in this generator is that instead of looping through the individual searches and path generations, path generations are recursivly called within the walk funciton. 


### algorithm is as follows:

1. start at a random room and mark it as visited
2. randomly select an adjacent, unvisited, in bounds room
3. advance to the selected room and mark it as visited
4. remove the wall between the previous and current room
5. repeat steps 2 - 4 until all adjacent rooms have been visited or are out of bounds
6. traverse the maze room by room checking for an unvisted room with an adjacent visited room
   * if found, recall steps 2-5 starting at the visited room
   * if none are found, end
