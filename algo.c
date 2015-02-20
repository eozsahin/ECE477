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

Point *insertionSortProbs(Point m[MATRIX_SIZE][MATRIX_SIZE],Point arr[MATRIX_SIZE*MATRIX_SIZE]){
    int row,col;
    int count = 0;
    //create an array of points 

    for(row = 0; row < MATRIX_SIZE; row++ ){
        for(col = 0; col < MATRIX_SIZE; col++){
            if(m[row][col].prob > 0 && m[row][col].firedUpon == FALSE){
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

void fire_insertionSort(Point *arr,int size){

    int  i,j;
    Point temp;

    

    for (i = 1; i < size; i++) {
      temp = arr[i];
      j = i - 1;
      while ((temp.prob > arr[j].prob) && (j >= 0)) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }
   return;
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

    int overall_prob = remaining_ship_freq[3]*ship_placement_5 +
                        remaining_ship_freq[2]*ship_placement_4 +
                        remaining_ship_freq[1]*ship_placement_3 +
                        remaining_ship_freq[0]*ship_placement_2;

    m[row][col].prob = overall_prob;
}

void fire_calcProbability(Point m[MATRIX_SIZE][MATRIX_SIZE], int *remaining_ship_freq,int row, int col){

}

Point hunt_findShot(Point m[MATRIX_SIZE][MATRIX_SIZE], int *remaining_ship_freq){
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
    int size = 0;

    printf("\nsorted probs:\n");
    Point arr[MATRIX_SIZE*MATRIX_SIZE/2] = {0};
    insertionSortProbs(m,arr);
    for(row = 0; row < MATRIX_SIZE*MATRIX_SIZE/2; row++){
        printf("point(%d,%d): prob: %d\n",arr[row].x,arr[row].y,arr[row].prob);
        if(arr[row].prob > 0)
            size++;
    }

    // time_t seconds;
    // time(&seconds);
    // srand((unsigned int) seconds);

    int lowerBound = 0;
    int upperBound = PRECISION;
    if(size < PRECISION)
        upperBound = size;
    int rndValue = lowerBound + rand() % (upperBound - lowerBound);
    printf("\n**rnd value: %d ,selected point is (%d,%d) with prob %d\n",rndValue,arr[rndValue].x,arr[rndValue].y,arr[rndValue].prob);

    return arr[rndValue]; 
    /*printf("\n**selected point is (%d,%d) with prob %d\n",arr[0].x,arr[0].y,arr[0].prob);

    return arr[0];*/

}



Point fire_findShot(Point m[MATRIX_SIZE][MATRIX_SIZE], int *remaining_ship_freq, Point target_point, int fire_dir){
    Point arr[ARR_FIRE_SIZE] = {0};
    Point idle_point;
    idle_point.prob = 0;
    idle_point.x = 0;
    idle_point.y = 0;
    arr[0] = idle_point;
    int ind = 0;
    int row;

    //DIFFERENT PROB CALCULATION NEEDED FOR FIRE 

    if(!m[target_point.x][target_point.y].firedUpon){
        printf("Error: Given target_point is null\n");
        return arr[0];
    } else {
        int row = target_point.x;
        int col = target_point.y;

        if(fire_dir == FIRE_IDLE){
            //check probability for north and south
            
            //FIRE_COL  
            if(row - 1 >= 0 ){
                //check north
                if(m[row-1][col].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row-1,col);
                    arr[ind] = m[row-1][col];
                    ind++;
                }
            }

            if(row + 1 < MATRIX_SIZE){
                //check south
                if(m[row+1][col].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row+1,col);
                    arr[ind] = m[row+1][col];
                    ind++;
                }
            }

            //FIRE_ROW
            if(col - 1 >= 0 ){
                //check west
                if(m[row][col-1].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row,col-1);
                    arr[ind] = m[row][col-1];
                    ind++;
                }
            }

            if(col + 1 < MATRIX_SIZE){
                //check east
                if(m[row][col+1].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row,col+1);
                    arr[ind] = m[row][col+1];
                    ind++;
                }
            }
        } else if(fire_dir == FIRE_ROW){
            
            //FIRE_ROW
            if(col - 1 >= 0 ){
                //check west
                if(m[row][col-1].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row,col-1);
                    arr[ind] = m[row][col-1];
                    ind++;
                }
            }

            if(col + 1 < MATRIX_SIZE){
                //check east
                if(m[row][col+1].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row,col+1);
                    arr[ind] = m[row][col+1];
                    ind++;
                }
            }

        } else if(fire_dir == FIRE_COL){

            //FIRE_COL  
            if(row - 1 >= 0 ){
                //check north
                if(m[row-1][col].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row-1,col);
                    arr[ind] = m[row-1][col];
                    ind++;
                }
            }

            if(row + 1 < MATRIX_SIZE){
                //check south
                if(m[row+1][col].firedUpon == FALSE){
                    calcProbability(m,remaining_ship_freq,row+1,col);
                    arr[ind] = m[row+1][col];
                    ind++;
                }
            }
             
        }

        


        //sort the arr and pick rand point given precision
        fire_insertionSort(&arr[0],ind);
        for(row = 0; row < ARR_FIRE_SIZE; row++){
            printf("point(%d,%d): prob: %d\n",arr[row].x,arr[row].y,arr[row].prob);
        }

        return arr[0];

    }
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



void displayMatrix(Point m[MATRIX_SIZE][MATRIX_SIZE], int opt){
    int i,j;
    
    for(i = 0; i < MATRIX_SIZE; i++){
        for(j = 0; j < MATRIX_SIZE; j++){

            switch(opt){

                case PRINT_SHIPS:
                    if(!i && !j)
                        printf("\n\n Displaying Ships: \n\n");
                    printf("%d ",m[i][j].shipSize);
                    
                    break;

                case PRINT_PROB:
                    if(!i && !j) 
                        printf("\n\n Displaying Probabilities: \n\n");
                    printf("%d ",m[i][j].prob);
                    
                    break;

                case PRINT_FIREDUPON:
                    if(!i && !j) 
                        printf("\n\n Displaying firedUpOn: \n\n");
                    if(m[i][j].shipExists){
                        printf("*%d ",m[i][j].firedUpon);
                    } else {
                        printf("%2d ",m[i][j].firedUpon);
                    }
                    break;

                case PRINT_SHIP_ID:
                    if(!i && !j) 
                        printf("\n\n Displaying Ships ID's: \n\n");
                    printf("%d ",m[i][j].id);
                    break;    

            }
            
        }
        printf("\n");
    }

    printf("-------------------------\n");
}

int isEndOfGame(Point m[MATRIX_SIZE][MATRIX_SIZE]){
    int row,col;
    int destroyed = TRUE;

    for(row = 0; row < MATRIX_SIZE; row++){
        for(col = 0; col < MATRIX_SIZE; col++){
            if(m[row][col].id != 0 && m[row][col].firedUpon == FALSE){
                destroyed = FALSE;
                return destroyed;
            }
        }
    }

    return destroyed;
}

int ifShipDestroyed(Point m[MATRIX_SIZE][MATRIX_SIZE],int id){
    int row,col;
    int destroyed = TRUE;

    for(row = 0; row < MATRIX_SIZE; row++){
        for(col = 0; col < MATRIX_SIZE; col++){
            if(m[row][col].id == id && m[row][col].firedUpon == FALSE){
                destroyed = FALSE;
                return destroyed;
            }
        }
    }

    return destroyed;
    
}

int ifSameShip(Point m[MATRIX_SIZE][MATRIX_SIZE],Point p1, Point p2 ){
    if(m[p1.x][p1.y].id == m[p2.x][p2.y].id 
        && m[p1.x][p1.y].id != 0){
        return SUCCESS;
    }

    return FAIL;

}

void displayFireDir(int fire_dir){
    if(fire_dir == FIRE_IDLE){
        printf("fire_dir: FIRE_IDLE\n");
    } else if(fire_dir == FIRE_ROW){
        printf("fire_dir: FIRE_ROW\n");
    } else if(fire_dir == FIRE_COL){
        printf("fire_dir: FIRE_COL\n");
    } else {
        printf("fire_dir: ERROR\n"); 
    }
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
    int mode;
    Point m[MATRIX_SIZE][MATRIX_SIZE];
    int remaining_ship_freq[4] = {3,2,2,1};
    srand(time(NULL));


    /*

    Available ships:
    size 2, freq 3
    size 3, freq 2
    size 4, freq 2
    size 5, freq 1
    
   
    

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
    int containsShip = 0;
    Point target_point;
    FILE *fptr = fopen("results.txt", "w");
    int ship_counter = 0;
    Point last_successfull_point;
    int fire_dir = FIRE_IDLE; 
    int shipDestroyed = FALSE;
    Point first_s_point;
    int fire_counter = 0;

    //implement a circular buffer with all successfull attemps for one ship
    // so that you can try all the possibilities in while loop by calling fire_findshot

    //game loop    
    while(not_destroyed){
        printf("\n^^^^^^^^^^^^^^^^^^^  round %d  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n",counter);

         //set the mode
        int mode = (fire_counter > 0 && !shipDestroyed)? MODE_FIRE : MODE_HUNT;
        printf("target_point: (%d,%d), fired %d \n",target_point.x,target_point.y,target_point.firedUpon);
        //hunting mode
        if(mode == MODE_HUNT){
            fire_counter = 0;
            printf(" mode: HUNT\n ");
            target_point = hunt_findShot(m,remaining_ship_freq);
        } else if(mode == MODE_FIRE){
            if(fire_counter == 1)
                first_s_point = last_successfull_point;

            displayFireDir(fire_dir);
            printf("last_successfull_point: (%d,%d)\n",last_successfull_point.x,last_successfull_point.y);
            target_point = fire_findShot(m,remaining_ship_freq,last_successfull_point, fire_dir);

            if(target_point.prob == 0){
                printf("trying with point: (%d,%d)\n",first_s_point.x,first_s_point.y);
                target_point = fire_findShot(m,remaining_ship_freq,first_s_point, fire_dir);
            }
    
        }
             
        printf("target_point: (%d,%d)\n",target_point.x,target_point.y);
        containsShip = fire(target_point,m);   

        //if shot is succesfull, update point
        //update position in which  
        if(containsShip){
            fire_counter++;
            //check if it is the second successfull shot
            if(fire_counter > 1){
                if(target_point.x == last_successfull_point.x && ifSameShip(m,target_point,last_successfull_point)){
                    fire_dir = FIRE_ROW;
                } else if(target_point.y == last_successfull_point.y && ifSameShip(m,target_point,last_successfull_point)){
                    fire_dir = FIRE_COL;
                } else {
                    fire_dir = FIRE_IDLE;
                }
            } else {
                fire_dir = FIRE_IDLE;
            }
            last_successfull_point = target_point;

            //check if ship is destroyed
            shipDestroyed = ifShipDestroyed(m,target_point.id);

            if(shipDestroyed){

                not_destroyed = isEndOfGame(m)? FALSE : TRUE;
                int temp_size = target_point.shipSize ;
                remaining_ship_freq[temp_size-2] = remaining_ship_freq[temp_size-2] - 1;
                printf("new frequency of size %d: %d\n",temp_size,remaining_ship_freq[temp_size-2]);
            } 

        }

        printf("\nis ship destroyed: %d\n",shipDestroyed);
    

        printf("ship: %d",containsShip);
        displayMatrix(m,PRINT_FIREDUPON);
        outProbResults(m,fptr,counter);

        if(counter == 64){
            printf(" \n\n *******65th shot game ended\n\n\n");
                break;
         }

        counter++;
    }

    fclose(fptr);
    printf("\nrounds ended\n");
    printf("\nfinished on round: %d\n\n",counter);
    if(isEndOfGame)
        printf("\n****** VICTORY ******\n");

    
    displayMatrix(m,PRINT_PROB);
    displayMatrix(m,PRINT_SHIPS);
    displayMatrix(m,PRINT_FIREDUPON);



    return;
}


