#include <stdlib.h>
#include <time.h>
#include "E:\programming projects\maze-generator\inc\generation.h"

#define ROWS 15
#define COLUMNS 15

#include <stdio.h>
#include "E:\programming projects\maze-generator\inc\output.h"


//function that generates the maze when given an array
void generateMaze(char maze[ROWS][COLUMNS]){
    int visitations[ROWS][COLUMNS] = {0}; //array to keep track of what rooms have been visited
    int x, y, i, j;

    srand(time(0));
    fillMaze(maze);
    
    //start the walk at a random location within the maze
    i = (rand() % (ROWS - 2) / 2) * 2 + 1;     //scales to [1, rows - 2] only odd numbers
    j = (rand() % (COLUMNS - 2) / 2) * 2 + 1;

    walk(i, j, maze, visitations);
    
}


//searches the arr for the adjavent rooms that are unique. assigns the room that
// has been visted to (j, i) so the next walk can be started
// returns 1 if the end of the arr has been reached
int findNextWalk(int *i, int *j, int visitations[ROWS][COLUMNS]){
    int endOfArr = 0;
    int col;
    
    for(int row = 1; row < ROWS; row += 2){
        for(col = 1; col < COLUMNS; col += 2){
            //check current room and adjacent east are different and the east is in bounds
            if(visitations[row][col] != visitations[row][col + 2] && !outOfBounds(row, col + 2, visitations)){
                //if the room has been visited and is not out of bounds set i and j
                if(visitations[row][col]){
                    *i = row;
                    *j = col;
                    return 1;
                    }
                else{
                    *i = row;
                    *j = col + 2;
                    return 1;  
                }
            }

            //check current room and adjacent south are different and the south is in bounds
            else if(visitations[row][col] != visitations[row + 2][col] && !outOfBounds(row + 2, col, visitations)){
                //if the room has been visited and is not out of bounds set i and j
                if(visitations[row][col]){
                    *i = row;
                    *j = col;
                    return 1;
                    }
                else{
                    *i = row + 2;
                    *j = col;
                    return 1;  
                }
            }
        }
    }

    return 0;
}

void walk(int i, int j, char maze[ROWS][COLUMNS], int visitations[ROWS][COLUMNS]){
    int canWalk = 1;
    int offLimits;
    int x = 0, y = 0, N, S, E, W;

    while(canWalk){
        //updates the maze and the current coordinates
        maze[i + y / 2][j + x / 2] = ' ';
        i += y;
        j += x;   

        //sets the current square that is visited to 1
        visitations[i][j] = 1;     
        
        //gets a valid direction
        N = 0, S = 0, E = 0, W = 0; //reset directional values
        do{
            getDirection(&x, &y);

            //checks if the direction is north, south, east, or west
            canWalk = !(N && S && E && W); //if every direction has been checked, STOP
            if      (!x && y > 0)   N = 1;
            else if (!x && y < 0)   S = 1;
            else if (x > 0 && !y)   E = 1;
            else                    W = 1;

            //checks bounds and makes sure the room has not been visited
            offLimits = outOfBounds(i + y, j + x, visitations);
            offLimits += visitations[i + y][j + x] == 1;
        }while(offLimits && canWalk);
    }

    //recursivly calls the walk function in order to generate paths throughout the rest of the maze
    if(findNextWalk(&i, &j, visitations)) {
        walk(i, j, maze, visitations);
        }
}

int outOfBounds(int i, int j, int visitations[ROWS][COLUMNS]){
    int offLimits;

    //checks the bounds and if the room has been visited
    offLimits = i <= 0 || i >= ROWS - 1;
    offLimits += j <= 0 || j >= COLUMNS - 1;

    return offLimits;
}

//sets x and y to a random cardinal direction multiplied by two
void getDirection(int *x, int *y){
    int val;
    *x = 0;
    *y = 0;

    //gets -2 or 2
    do{
        val = (rand() % 3 - 1) * 2;
    }while(!val);

    //chooses a random direction to shift the array
    if(rand() % 2) *x =+ val;
    else           *y =+ val;
}

//generates a blank maze of empty rooms
void fillMaze(char maze[ROWS][COLUMNS]){
    int j;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            if(i % 2){
                if(j % 2) maze[i][j] = ' ';
                else      maze[i][j] = '#';
            }
            else maze[i][j] = '#';
        }
    }
}