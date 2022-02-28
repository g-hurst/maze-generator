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
    int rows = 15, cols = 15;
    char** mzStack;

    // allocates memeory for the maze
    mzStack = malloc(rows * sizeof(*mzStack));
    for (int i = 0; i < cols; i++) {
        mzStack[i] = malloc(cols * sizeof(mzStack));
    }

    generateMaze(maze);       //generates the maze

    // assigns values to the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mzStack[i][j] = maze[i][j];
        }
    }

    outputText(mzStack, rows, cols);        //outputs the maze to a text file

    outputTerminal(mzStack, rows, cols);    //outputs the maze to the terminal

    // frees allocated memory
    for (int i = 0; i < cols; i++) {
        free(mzStack[i]);
    }
    free(mzStack);
    return 0;
}
