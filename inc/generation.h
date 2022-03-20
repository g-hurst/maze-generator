#ifndef GENERATION_H_
#define GENERATION_H_

#define ROWS 15
#define COLUMNS 15

void fillMaze(char**, int, int);
void generateMaze(char**, int, int);
void createHoles(char**, int, int);

void walk(int, int, char**, int**, int, int);
int findNextWalk(int*, int*, int**, int, int);

int outOfBounds(int, int, int, int);
void getDirection(int*, int*);


#endif
