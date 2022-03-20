#include "../inc/output.h"
#include "../inc/generation.h"
#include <stdlib.h>
#include "../inc/clog.h"

#define ROWS 15
#define COLUMNS 15
/*
struct Maze{
    int rows, cols;
    char **arr;
    int **vis;
};
*/
int main(){
    int rows = 15, cols = 15;
    char** mzStack = malloc(rows * sizeof(*mzStack));
    
    for (int i = 0; i < cols; i++) {
        mzStack[i] = malloc((cols + 1) * sizeof(*mzStack[i]));
        mzStack[i][cols] = '\0';
    }

    generateMaze(mzStack, rows, cols);       //generates the maze

    outputText(mzStack, rows, cols);        //outputs the maze to a text file

    outputTerminal(mzStack, rows, cols);    //outputs the maze to the terminal


    // frees allocated memory
    for (int i = 0; i < cols; i++) {
        free(mzStack[i]);
    }
    free(mzStack);

    return 0;
}
