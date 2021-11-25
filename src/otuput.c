#include <stdio.h>
#include "E:\programming projects\maze-generator\inc\output.h"
#define ROWS 15
#define COLUMNS 15

//outputs the maze to a text file
void outputText(char maze[ROWS][COLUMNS]){
    FILE *fp;
    char newLineChar = '\n';
    fp = fopen("mazeTextOutput/maze.txt", "w");
    for(int i = 0; i < ROWS; i++){
        fputc(newLineChar, fp);
        for(int j = 0; j < COLUMNS; j++){
            fputc(maze[i][j], fp);
        }
    }
}

//displays the maze to the terminal
void outputTerminal(char maze[ROWS][COLUMNS]){
    for(int i = 0; i < ROWS; i++){
        printf("\n");
        for(int j = 0; j < COLUMNS; j++){
            printf("%c", maze[i][j]);
        }
    }
}

//displays the maze to the terminal
void outputVisitationsTerminal(int visitations[ROWS][COLUMNS]){
    for(int i = 0; i < ROWS; i++){
        printf("\n");
        for(int j = 0; j < COLUMNS; j++){
            printf("%d", visitations[i][j]);
        }
    }
}