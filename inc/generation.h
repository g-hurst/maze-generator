#ifndef GENERATION_H_
#define GENERATION_H_

#define ROWS 15
#define COLUMNS 15


void generateMaze(char[ROWS][COLUMNS]);
void fillMaze(char[ROWS][COLUMNS]);
void firstWalk(int, int, char[ROWS][COLUMNS], int[ROWS][COLUMNS]);
void mazeify(int, int, char[ROWS][COLUMNS], int[ROWS][COLUMNS]);
int findUnvisited(int*, int*, int[ROWS][COLUMNS]);
void getDirection(int*, int*);


#endif