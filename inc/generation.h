#ifndef GENERATION_H_
#define GENERATION_H_

#define ROWS 15
#define COLUMNS 15

void fillMaze(char[ROWS][COLUMNS]);
void generateMaze(char[ROWS][COLUMNS]);
void createHoles(char[ROWS][COLUMNS]);

void walk(int, int, char[ROWS][COLUMNS], int[ROWS][COLUMNS]);
int findNextWalk(int*, int*, int[ROWS][COLUMNS]);

int outOfBounds(int, int, int[ROWS][COLUMNS]);
void getDirection(int*, int*);


#endif