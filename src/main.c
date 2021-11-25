#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "E:\programming projects\maze-generator\inc\output.h"

#define ROWS 15
#define COLUMNS 15

void fillMaze(char maze[ROWS][COLUMNS]);

void firstWalk(int i, int j, char maze[ROWS][COLUMNS], int visitations[ROWS][COLUMNS]);
void mazeify(int i, int j, char maze[ROWS][COLUMNS], int visitations[ROWS][COLUMNS]);
int findUnvisited(int *i, int *j, int visitations[ROWS][COLUMNS]);
void getDirection(int *x, int *y);

int main(){
    char maze[ROWS][COLUMNS];
    int visitations[ROWS][COLUMNS] = {0}; //
    int x, y, i, j;

    srand(time(0));
    fillMaze(maze);
    
    //start the walk at a random location within the maze
    i = (rand() % (ROWS - 2) / 2) * 2 + 1;     //scales to [1, rows - 2] only odd numbers
    j = (rand() % (COLUMNS - 2) / 2) * 2 + 1;

    firstWalk(i, j, maze, visitations);
    mazeify(i, j, maze, visitations);

    outputText(maze);
    outputTerminal(maze);
    //outputVisitationsTerminal(visitations);

    return 0;
}

//searches the loop for the next unvisited room starting at (j, i); returns 1 if the end of the arr has been reached
int findUnvisited(int *i, int *j, int visitations[ROWS][COLUMNS]){
    int endOfArr = 0;
    int col;
    
    for(int row = 1; row < ROWS; row += 2){
        for(col = 1; col < COLUMNS; col += 2){
            if(visitations[row][col] == 0){
                *i = row;
                *j = col;
                return 0;;
            }
        }
    }

    return 1;
}

void firstWalk(int i, int j, char maze[ROWS][COLUMNS], int visitations[ROWS][COLUMNS]){
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

            //assures that the point is valid
            offLimits = i + y <= 0 || i + y >= ROWS - 1;
            offLimits += j + x <= 0 || j + x >= COLUMNS - 1;
            offLimits += visitations[i + y][j + x] == 1;
        }while(offLimits && canWalk);
    }
}

//genrates the remaining portion of the maze after the first walk has been performed
void mazeify(int i, int j, char maze[ROWS][COLUMNS], int visitations[ROWS][COLUMNS]){
    int pathNotFound = 1;
    int offLimits;
    int x = 0, y = 0, xOld, yOld;

    //findUnvisited(&i, &j, visitations);
    
    while(pathNotFound){
        xOld = x;
        yOld = y;

        //sets the current square to visited
        visitations[i][j] = 1;

        do{
            getDirection(&x, &y);

            //checks to see if the direction is out of bounds and not back tracking
            offLimits = i + y <= 0 || i + y >= ROWS - 1;
            offLimits += j + x <= 0 || j + x >= COLUMNS - 1;
            offLimits += -x == xOld && -y == yOld;
        }while(offLimits);
        
        //updates the maze and the current coordinates
        i += y;
        j += x;
        maze[i - y / 2][j - x / 2] = ' ';

        //checks if the space has been visited
        if(visitations[i][j] == 1) pathNotFound = 0; 
    }

    //recursivly calls the mazify function to fill the rest of the maze
    if(findUnvisited(&i, &j, visitations) == 0) mazeify(i, j, maze, visitations);
}

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




