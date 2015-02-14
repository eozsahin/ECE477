#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SUCCESS 1
#define FAIL 0

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