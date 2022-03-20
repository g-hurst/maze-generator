#include "../inc/output.h"
#include "../inc/generation.h"
#include <stdlib.h>
#include "../inc/clog.h"

int main(){
    int size;
	do {
		printf("Enter size: ");
		scanf("%d", &size);
		if(size < 3 || size % 2 == 0) {
			printf("Error: size must be greater than 3 and odd\n");
		}
	} while(size < 3 || size % 2 == 0);

    char** mzStack = malloc(size * sizeof(*mzStack));
    for (int i = 0; i < size; i++) {
        mzStack[i] = malloc((size + 1) * sizeof(*mzStack[i]));
        mzStack[i][size] = '\0';
    }

    generateMaze(mzStack, size, size);       //generates the maze

    outputText(mzStack, size, size);        //outputs the maze to a text file

    outputTerminal(mzStack, size, size);    //outputs the maze to the terminal


    // frees allocated memory
    for (int i = 0; i < size; i++) {
        free(mzStack[i]);
    }
    free(mzStack);

    return 0;
}
