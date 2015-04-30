/* Activator/Inhibitor CA 
   By Chi Zhang */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int state[SIZE][SIZE] = {0};
int stateNext[SIZE][SIZE]={0};
int R1, R2, h, J1, J2;

int fillArray();
int printArray();
bool checkNeighbor();
int swapGrids();


void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}


int main(int argc, char *argv[]){

	printf("\n****************** Activator/Inhibitor CA ******************\n");
	if(argc != 6 ){
		printf("Usage:\n./aica J1 J2 R1 R2 h\n");
		exit(0);
	}
	else{
		J1 = atoi(argv[1]);
		J2 = atoi(argv[2]);
		R1 = atoi(argv[3]);
		R2 = atoi(argv[4]);
		h = atoi(argv[5]);
	}
	printf("J1 = %d, J2 = %d, R1 = %d, R2 = %d, h = %d\n", J1, J2, R1, R2, h);
	fillArray();
	int step = 20;
	while(step--){
		wait(1);
	    printArray();
        checkNeighbor();
        swapGrids();
	}
	
	return 0;
}

int fillArray(){
    //fill the array with random junk, either -1 or 1
	int random=0;
    srand(time(NULL));

	for(int i = 0;i < SIZE; i++){
		for(int j = 0;j < SIZE; j++){
			random=rand()%2+0;
			if (random == 0)
				random = -1;
            state[i][j] = random;
		}
	}
return 0;
}

int printArray(){
    //print all the stuff that's been pushed into our array
	printf("\n---\n");
	for(int i = 0;i < SIZE;i++){
		printf("\n");
		for(int j = 0; j < SIZE; j++){
            if(state[i][j] == 1)
				printf("+ ", state[i][j]);
			else
				printf("  ",state[i][j]);
		}
	}
  return 0;
}

bool checkNeighbor(){
	//check a cell's neighbors
	int sum_act = 0;
	int sum_inh = 0;
	int r_ij = 0;
	
	int i1, i2;
	

	for(int i = 0; i < SIZE; i++)
		for(int j = 0 ; j < SIZE; j++)
			stateNext[i][j] = state[i][j];
	
	for(i1 = 0; i1 < SIZE; i1++){
		for(i2 = 0; i2 < SIZE; i2++)
		{
			for (int j1 = 0; j1 < SIZE; j1++){
				for(int j2 = 0; j2 < SIZE; j2++){
					int x = abs(i1 - j1);
					int y = abs(i2 - j2);

					if (x > SIZE/2)
						x = SIZE - x;
					if ( y > SIZE/2)
						y = SIZE - y;
					r_ij = x + y;	
					if(r_ij < R1)	
						sum_act += state[j1][j2];	
					if(r_ij >= R1 && r_ij <R2)	
						sum_inh += state[j1][j2];
				}
			}
		if (float(h + J1 * sum_act + J2 * sum_inh) >= 0)
			stateNext[i1][i2] = 1;
		else if (float(h + J1 * sum_act + J2 * sum_inh) < 0)
			stateNext[i1][i2] = -1;
		else
			;//puts("Error, no sum");
		}
	}
	return true;
}



int swapGrids(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0;j < SIZE; j++){
            state[i][j] = stateNext[i][j];
		}
	}
return 0;
}

