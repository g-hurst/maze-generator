#include <stdio.h>
#include "E:\programming projects\maze-generator\inc\output.h"
#define ROWS 15
#define COLUMNS 15

//outputs the maze to a text file
void outputText(char maze[ROWS][COLUMNS]){
    FILE *fp;
    char start[11] = "\nSTART--> \0";
    char blank[11] = "\n         \0";
    char end[8]    = " <--END\0";
    fp = fopen("mazeTextOutput/maze.txt", "w");
    for(int i = 0; i < ROWS; i++){
        //prints start
        if(maze[i][0] == '#') fputs(blank, fp);
        else fputs(start, fp);

        //prints meat of maze
        for(int j = 0; j < COLUMNS; j++){
            fputc(maze[i][j], fp);
        }

        //prints end
        if(maze[i][COLUMNS - 1] == ' ') fputs(end, fp);
    }
}

//displays the maze to the terminal
void outputTerminal(char maze[ROWS][COLUMNS]){
    for(int i = 0; i < ROWS; i++){
        //prints start
        if(maze[i][0] == '#') printf("\n         ");
        else printf("\nSTART--> ");
        
        //prints meat of maze
        for(int j = 0; j < COLUMNS; j++){
            printf("%c", maze[i][j]);
        }

        //prints end
        if(maze[i][COLUMNS - 1] == ' ') printf(" <--END");
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