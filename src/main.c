#include "../inc/output.h"
#include "../inc/generation.h"
#include <stdlib.h>
#include "../inc/clog.h"

int main(){
    int rows, cols;
	printf("Enter rows: ");
	scanf("%d", &rows);
	printf("Enter cols: ");
	scanf("%d", &cols);

    char** mzStack = malloc(rows * sizeof(*mzStack));
    for (int i = 0; i < rows; i++) {
        mzStack[i] = malloc((cols + 1) * sizeof(*mzStack[i]));
        mzStack[i][cols] = '\0';
    }

    generateMaze(mzStack, rows, cols);       //generates the maze

    outputText(mzStack, rows, cols);        //outputs the maze to a text file

    outputTerminal(mzStack, rows, cols);    //outputs the maze to the terminal


    // frees allocated memory
    for (int i = 0; i < rows; i++) {
        free(mzStack[i]);
    }
    free(mzStack);

    return 0;
}
