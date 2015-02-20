#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SUCCESS 1
#define FAIL 0

#define MODE_FIRE 99
#define MODE_HUNT 100

#define ARR_FIRE_SIZE 4

#define PRINT_PROB -1
#define PRINT_SHIP_ID -2
#define PRINT_FIREDUPON -3
#define PRINT_SHIPS -4 

#define FIRE_ROW -10
#define FIRE_COL -11
#define FIRE_IDLE -12

typedef int bool;
#define TRUE 1
#define FALSE 0

#define ARG 3
#define MATRIX_SIZE 8	

//pick between 0 and 5
// 0 is better and 5 is the lowest
#define PRECISION 3		

typedef struct {
  bool shipExists;
  int id;
  int shipSize;
  bool firedUpon;
  int prob;
  int x;
  int y;
} Point;