#include "algo.h"
      

void placeShips(Point m[MATRIX_SIZE][MATRIX_SIZE]){
        // place ships in the matrix
    int row,col = 0;
    for(row=0; row < MATRIX_SIZE;row++){
        for(col=0; col < MATRIX_SIZE;col++){
            m[row][col].x = row;
            m[row][col].y = col;

            //place ship 5 on row 0
            if((col > 0 && col < 6) && (row == 0)){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 5; 
                m[row][col].id = 1;  
            } 
            //ship size 2 column 0
            else if(col == 0 && (row > 1 && row < 4)){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 2; 
                m[row][col].id = 2; 
            } 
            //ship size row 2
            else if(row == 2 && (col > 4 && col < 7)){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 2; 
                m[row][col].id = 3; 
            }
            //ship size 2 col 4 
            else if(col == 4 && (row > 5)){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 2; 
                m[row][col].id = 4; 
            }
            //ship size 3 row 7
            else if(row == 7 && (col < 3)){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 3; 
                m[row][col].id = 5; 
            }
            //ship size 3 col 6
            else if(col == 6 && row > 4){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 3; 
                m[row][col].id = 6; 
            }
            //ship size 4 col 2
            else if(col == 2 && (row > 1 && row < 6)){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 4; 
                m[row][col].id = 7; 
            }
            //ship size 4 row 4
            else if( row == 4 && col > 3){
                m[row][col].shipExists = TRUE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 4; 
                m[row][col].id = 8; 
            } else{
                m[row][col].shipExists = FALSE;
                m[row][col].firedUpon = FALSE;
                m[row][col].prob = 0;
                m[row][col].shipSize = 0; 
                m[row][col].id = 0; 
            }

        }
    }
}

Point *insertionSort(Point m[MATRIX_SIZE][MATRIX_SIZE],Point arr[MATRIX_SIZE*MATRIX_SIZE/2]){
    int row,col;
    int count = 0;
    //create an array of points 

    for(row = 0; row < MATRIX_SIZE; row++ ){
        for(col = 0; col < MATRIX_SIZE; col++){
            if(m[row][col].prob){
                arr[count] = m[row][col];
                count++;
            }
        }
    }


    //sort array items 
    int  i,j;
    Point temp;
    for (i = 1; i < count; i++) {
      temp = arr[i];
      j = i - 1;
      while ((temp.prob > arr[j].prob) && (j >= 0)) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }



   return arr;
}

int checkShips(Point m[MATRIX_SIZE][MATRIX_SIZE], int size, int row, int col){
    
    int i;
    int j;
    int column = col;
    int rows = row;
    int hor_counter = 0;
    int ver_counter = 0;
    int temp_row ;
    int temp_col;
    bool available;

    

    //check horizontal probs
    for(i = 0; i < size; i++){
        available = TRUE;
        
        if((column - size + 1 >= 0) && (column  < MATRIX_SIZE)){
            temp_col = column - size + 1;
            for(j = temp_col; j <= column;j++){
                

                if(m[row][j].firedUpon == TRUE){
                   available = FALSE;
                   j = column;
                } 
                    
            }
        } else {
            available = FALSE;
        }

        
        if(available){
            hor_counter++;
        }
        
        column++;
    }


    //check vertical probs
    for(i = 0; i < size; i++){
        available = TRUE;
        if((rows - size + 1 >= 0) && (rows < MATRIX_SIZE)){
            
            temp_row = rows - size + 1;
            for(j = temp_row; j <= rows ; j++){
                 if(m[j][col].firedUpon == TRUE){
                    available = FALSE;
                    j = rows;
                } 
            }
        } else {
            available = FALSE;
        }

        
        if(available){
            ver_counter++;
        }

        rows++;
    }

    //printf("size %d row %d col %d: ver_counter %d, hor_counter %d\n",size,row,col,ver_counter,hor_counter);
    
    return hor_counter + ver_counter;
}

void calcProbability(Point m[MATRIX_SIZE][MATRIX_SIZE],int *remaining_ship_freq,int row,int col){
    int ship_placement_5 = checkShips(m,5,row,col);
    int ship_placement_4 = checkShips(m,4,row,col);
    int ship_placement_3 = checkShips(m,3,row,col);
    int ship_placement_2 = checkShips(m,2,row,col);

    int overall_prob = remaining_ship_freq[0]*ship_placement_5 +
                        remaining_ship_freq[1]*ship_placement_4 +
                        remaining_ship_freq[2]*ship_placement_3 +
                        remaining_ship_freq[3]*ship_placement_2;

    m[row][col].prob = overall_prob;
}

Point findBestShot(Point m[MATRIX_SIZE][MATRIX_SIZE], int *remaining_ship_freq){
    int row,col;

    //calculate probabilities of each checkerboard grid
    for(row = 0; row < MATRIX_SIZE;row++){
        for(col = 0; col < MATRIX_SIZE;col++){
            //check for checkerboard pattern
            if((row % 2) == 0 && (col % 2) == 0 || 
                (row % 2) == 1 && (col % 2) == 1){
                calcProbability(m,remaining_ship_freq,row,col);
            }
        }
    }

    //sort the possible options

    printf("\nsorted probs:\n");
    Point arr[MATRIX_SIZE*MATRIX_SIZE] = {0};
    insertionSort(m,arr);
    for(row = 0; row < MATRIX_SIZE*MATRIX_SIZE; row++){
        printf("point(%d,%d): prob: %d\n",arr[row].x,arr[row].y,arr[row].prob);
    }

    srand(time(NULL));
    int lowerBound = 0;
    int upperBound = PRECISION;
    int rndValue = lowerBound + rand() % (upperBound - lowerBound);
    printf("\n**selected point is (%d,%d) with prob %d\n",arr[rndValue].x,arr[rndValue].y,arr[rndValue].prob);

    return arr[rndValue];
}

int fire(Point single_point, Point m[MATRIX_SIZE][MATRIX_SIZE]){
    int row = single_point.x;
    int col = single_point.y;


    m[row][col].firedUpon = TRUE;
    if(m[row][col].shipExists == TRUE){
        return TRUE;
    } 

    return FALSE;
}





void displayProbs(Point m[MATRIX_SIZE][MATRIX_SIZE]){
    int i,j;
    printf("\n\n Displaying Probabilities: \n\n");
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            printf("%2d  ",m[i][j].prob);
        }
        printf("\n");
    }

    printf("-------------------------\n");
}

void displayMatrix(Point m[MATRIX_SIZE][MATRIX_SIZE]){
    int i,j;
    printf("\n\n Displaying Matrix: \n\n");
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            printf("%d ",m[i][j].shipSize);
        }
        printf("\n");
    }

    printf("-------------------------\n");
}

void displayFiredUpOn(Point m[MATRIX_SIZE][MATRIX_SIZE]){
    int i,j;
    printf("\n\n Displaying firedUpon: \n\n");
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){
            printf("%d ",m[i][j].firedUpon);
        }
        printf("\n");
    }

    printf("-------------------------\n");
}

void outProbResults(Point m[MATRIX_SIZE][MATRIX_SIZE], FILE *fptr,int round ){
    int row,col;
    fprintf(fptr,"prob_round_%d = [",round);
    for(row = 0; row < MATRIX_SIZE; row++){
        for(col = 0; col < MATRIX_SIZE; col++){
            fprintf(fptr, " %2d ",m[row][col].prob);
        }
        fprintf(fptr,";\n");
    }
    fprintf(fptr,"]\n");
}


int main(int argc, char *argv[])
{
    int row,col;
    Point m[MATRIX_SIZE][MATRIX_SIZE];
    int remaining_ship_freq[4] = {1,2,2,3};

    /*

    Available ships:
    size 5, freq 1
    size 4, freq 2
    size 3, freq 2
    size 2, freq 3

        0 1 2 3 4 5 6 7

    0   - 5 5 5 5 5 - -
    1   - - - - - - - -
    2   2 - 4 - - 2 2 - 
    3   2 - 4 - - - - - 
    4   - - 4 - 4 4 4 4
    5   - - 4 - - - 3 - 
    6   - - - - 2 - 3 - 
    7   3 3 3 - 2 - 3 -
    
    */

    placeShips(m);

    int not_destroyed = TRUE;
    int counter = 1;
    FILE *fptr = fopen("results.txt", "w");
    while(not_destroyed){
        printf("\n^^^^^^^^^^^^^^^^^^^  round %d  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^",counter);
        Point target_point = findBestShot(m,remaining_ship_freq);
        printf("target_point: (%d,%d)\n",target_point.x,target_point.y);
        int containsShip = fire(target_point,m);
        printf("ship: %d",containsShip);
        displayProbs(m);
        outProbResults(m,fptr,counter);

        if(counter == 6){
            break;
        }

        counter++;
    }

    fclose(fptr);

    Point target_point = findBestShot(m,remaining_ship_freq);
    printf("target_point: (%d,%d)\n",target_point.x,target_point.y);
    int containsShip = fire(target_point,m);
    printf("ship: %d",containsShip);
    displayProbs(m);
    displayMatrix(m);
    displayFiredUpOn(m);



    return;
}








