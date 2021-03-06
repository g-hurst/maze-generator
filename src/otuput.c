#include <stdio.h>
#include "../inc/output.h"

//outputs the maze to a text file
void outputText(char** maze, int rows, int cols)
{
    FILE *fp;
    char* start = "\nSTART--> ";
    char* blank = "\n         ";
    char* end   = " <--END";
    fp = fopen("mazeTextOutput/maze.txt", "w");
    for(int i = 0; i < rows; i++){
        //prints start
        if(maze[i][0] == '#') fputs(blank, fp);
        else fputs(start, fp);

        //prints meat of maze
        for(int j = 0; j < cols; j++){
            fputc(maze[i][j], fp);
        }

        //prints end
        if(maze[i][cols - 1] == ' ') fputs(end, fp);
    }
	fclose(fp);
}

//displays the maze to the terminal
void outputTerminal(char** maze, int rows, int cols){
    for(int i = 0; i < rows; i++){
        //prints start
        if(maze[i][0] == '#') printf("\n         ");
        else printf("\nSTART--> ");
        
        //prints meat of maze
        for(int j = 0; j < cols; j++){
            printf("%c", maze[i][j]);
        }

        //prints end
        if(maze[i][cols - 1] == ' ') printf(" <--END");
    }
}
