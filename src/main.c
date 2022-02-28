#include "../inc/output.h"
#include "../inc/generation.h"
#include <stdlib.h>

#define ROWS 15
#define COLUMNS 15

struct Maze{
    int rows, cols;
    char **arr;
    int **vis;
};



int main(){
    char maze[ROWS][COLUMNS];   //arr to create the maze

    generateMaze(maze);       //generates the maze

    outputText(maze);        //outputs the maze to a text file
    outputTerminal(maze);    //outputs the maze to the terminal

    return 0;
}
