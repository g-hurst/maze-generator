#include "E:\programming projects\maze-generator\inc\output.h"
#include "E:\programming projects\maze-generator\inc\generation.h"

#define ROWS 15
#define COLUMNS 15

int main(){
    char maze[ROWS][COLUMNS];   //arr to create the maze

    generateMaze(maze);         //generates the maze

    outputText(maze);           //outputs the maze to a text file
    outputTerminal(maze);       //outputs the maze to the terminal

    return 0;
}
