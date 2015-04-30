/* Activator Inhibitor CA -- Chi Zhang */

#include <time.h>
#include "pgm.cpp"
#include <algorithm>
#include <cmath>
#define SIZE 30
#define _e 2.718281828
using namespace std;

int state[SIZE][SIZE] = {0};
int stateTemp[SIZE][SIZE] = {0};
int R1, R2, h;
double J1, J2;

void  wait(float);
int fillArray();
int printArray();
bool checkNeighbor();
int recordGrids();
int createPGM(char *);
int checkConverge();
double calRho(int);
double calEnt(int);
double calHs();

int main(int argc, char *argv[]){
	
	/************* Usage *************/
	printf("\n************ Activator/Inhibitor CA ************\n   Usage:\n   ./aica J1 J2 R1 R2 h\n************************************************\n");
	if(argc != 6 ){
		printf("Usage:\n./aica J1 J2 R1 R2 h\n");
		exit(0);
	}
	else{
		J1 = atof(argv[1]);
		J2 = atof(argv[2]);
		R1 = atoi(argv[3]);
		R2 = atoi(argv[4]);
		h = atoi(argv[5]);
	}
	printf("Paramters:\n    J1 = %f, J2 = %f, R1 = %d, R2 = %d, h = %d\n", J1, J2, R1, R2, h);

	
	/************* Initilize grids *************/
	fillArray();
	int step = 0;
	char filename[10];

	/************* Converge *************/
	while( !checkConverge())
	{	
		// Create image for each step
		
		sprintf(filename, "%d", step);
		printf("Snapshot step %d in file %s.pgm.\n\n\n",step, filename);
		createPGM(filename);
		
	//	printArray();
		recordGrids();	
		checkNeighbor();
	//	printf("checkConverge is %d in step %d\n", checkConverge(), step);
		step++;
	}
	
	sprintf(filename, "%d", step);
	printf("Snapshot step %d in file %s.pgm.\n\n\n",step, filename);
	createPGM(filename);

//	printf("AICA converges at  step %d\n", --step);
//	printArray();

	
	double rho[SIZE/2] = {0};
	double H[SIZE/2] = {0};
	double Hs = 0;
	
	double I[SIZE/2] = {0};
	/************* Calcuate rho ****************/
	for(int l = 0; l < SIZE/2; l++){
		rho[l] = calRho(l);
	//	printf("rho[%d]=%f, to rho[l]/e %f\n", l, rho[l], rho[l]/_e);
	}
	
	
	/************* Calculate H, I *************/
	Hs = calHs();
	for(int l = 1; l < SIZE/2; l++){
		H[l] = calEnt(l);	
		I[l] = 2 * Hs - H[l];
	//	printf("Hs %f; H[%d] %f; I[%d] %f\n",Hs, l, H[l], l, I[l]);
	}
	
	printf("rho[0]=%f, rho[0]/e=%f\n", rho[0], rho[0]/_e);
	for(int l = 1; l < SIZE/2; l++)
		printf("l=%d: rho=%f, H=%f, I=%f\n", l, rho[l], H[l], I[l]);

	printf("AICA converges at  step %d\n", step);	
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
			stateTemp[i][j] = state[i][j] - 1;
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
				printf("*", state[i][j]);
			else
				printf(" ",state[i][j]);
		}
	}
	printf("\n---\n");
	return 0;
}

bool checkNeighbor(){
	//check a cell's neighbors
	int r_ij = 0;
	
	int i1, i2;
	
	//Generate random # from 0 - 899
	int a[900] = {0};
	for(int i = 0; i < 900; i++){
		a[i] = i;
	}
	for(int i = 899; i > 0; i--){
	    swap(a[i], a[rand()%i]);
	}

	for(int i = 0; i < 900; i++){
		i1 = a[i] / 30;
		i2 = a[i] % 30;
		
		int sum_act = 0;
		int sum_inh = 0;

		for (int j1 = 0; j1 < SIZE; j1++){
			for(int j2 = 0; j2 < SIZE; j2++){
		
				int x = abs(i1 - j1);
				int y = abs(i2 - j2);

				if( x > 15)
					x = 30 - x;
				if ( y > 15)
					y = 30 - y;

				r_ij = x + y;
				
				if (r_ij < R1)
					sum_act += state[j1][j2];	
				if (r_ij >= R1 && r_ij < R2)
					sum_inh += state[j1][j2];
			}
		}

	//	printf("sum_act %d, sum_inh %d\t", sum_act, sum_inh);
		
		if (float(h + J1 * sum_act + J2 * sum_inh) >= 0){
			state[i1][i2] = 1;
		//	if (state[i1][i2] != stateTemp[i1][i2])
		//		puts("!!!!!!!!! Change state from -1 to 1.");
		}
		else if (float(h + J1 * sum_act + J2 * sum_inh) < 0){
			state[i1][i2] = -1;
		//	if (state[i1][i2] != stateTemp[i1][i2])
		//		puts("!!!!!!!!! Change state from 1 to -1.");	
		}
		else
			;//puts("Error, no sum");
			
		//	printArray();
		
	}
//	printf("Converge? %d\n", checkConverge());
	return true;
}

int recordGrids(){
	//Update grids
	for(int i = 0; i < SIZE; i++){
		for(int j = 0;j < SIZE; j++){
            stateTemp[i][j] = state[i][j];
		}
	}
	return 0;
}

int checkConverge(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0;j < SIZE; j++){
			if( stateTemp[i][j] != state[i][j])
				return 0;
		}
	}
	return 1;
}

int createPGM(char *filename){
	//Create PGM image
	int nr, nc;
	nc = SIZE;
	nr = SIZE;	

	unsigned char **img = NULL;
	unsigned char **pix = new unsigned char*[SIZE];
	
	img = createImage(nr, nc);
	if(!img)	
		puts("Failed create image.");

	unsigned char temp[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			temp[i][j] = (unsigned char)state[i][j];
		}

		pix[i] = temp[i];
	}

	strcat(filename, ".pgm");
 	int w = 0;
	w = writePGM(pix, nr, nc, nc, filename);
	if(w==1){
		return 1;	
	}
	else{
		puts("Failed write image");
		return 0;
	}
}


void wait (float seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

double calRho(int l){	
	double rho = 0;	
	
	int sum1 = 0;
	int sum2 = 0;
	for(int i1 = 0; i1 < SIZE; i1++){
		for(int i2 = 0; i2 < SIZE; i2++){
			int sum = 0;
			for(int j1 = 0; j1 <= l; j1++){
				int j2 = l - j1;
				
				int x1 = i1 + j1;
				int x2 = i1 - j1;
				x1 = (x1>= 30) ? (x1-30) : x1;
				x2 = (x2<= -1) ? (x2+30) : x2;

				int y1 = i2 + j2;
				int y2 = i2 - j2;
				y1 = (y1 >= 30) ? (y1-30) : y1;
				y2 = (y2 <= -1) ? (y2+30) : y2;

				if (x1 == x2)
					sum += state[x1][y1] + state[x1][y2];
				else if(y1 == y2)
					sum += state[x1][y1] + state[x2][y1];
				else
					sum += state[x1][y1] + state[x1][y2] + state[x2][y1] + state[x2][y2];
			}
//			printf("----> in Rho func, sum %d\n",sum);
			sum1 += sum * state[i1][i2];
			sum2 += state[i1][i2];
		}
	}
//	printf("sum1 %d; sum2 %d\n", sum1, sum2);
	if (l==0)
		rho = abs(1 - pow(double(sum2)/900,2)); 
	else
		rho = abs(sum1/(double)(4*l*SIZE*SIZE) - double(1/SIZE/SIZE*sum2) * double(1/SIZE/SIZE*sum2));
	
	return rho;
}

double calEnt(int l){
	int beta[SIZE][SIZE] = {0};
	int beta_[SIZE][SIZE] = {0};
	double sum = 0;
	double sum_ = 0;
	double pr11, pr_1_1, pr1_1;

	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			beta[i][j] = (state[i][j] + 1) / 2;
			beta_[i][j] = (-state[i][j] + 1) / 2;
		}
	}

	for(int i1 = 0; i1 < SIZE; i1++){
		for(int i2 = 0; i2 < SIZE; i2++){
			int sum1 = 0;
			int sum2 = 0;
			for(int j1 = 0; j1 <= l; j1++){
				int j2 = l - j1;
				
				int x1 = i1 + j1;
				int x2 = i1 - j1;
				x1 = (x1>= 30) ? (x1-30) : x1;
				x2 = (x2<= -1) ? (x2+30) : x2;

				int y1 = i2 + j2;
				int y2 = i2 - j2;
				y1 = (y1 >= 30) ? (y1-30) : y1;
				y2 = (y2 <= -1) ? (y2+30) : y2;

				if(x1 == x2){
					sum1 += beta[x1][y1] + beta[x1][y2];
					sum2 += beta_[x1][y1] + beta_[x1][y2];
				}
				else if(y1 == y2){
					sum1 += beta[x1][y1] + beta[x2][y1];
					sum2 += beta_[x1][y1] + beta_[x2][y1];
				}
				else if(x1 == x2 && y1 == y2){
					sum1 += beta[x1][y1];
					sum2 += beta_[x1][y1];
				}
				else{
					sum1 += beta[x1][y1] + beta[x1][y2] + beta[x2][y1] + beta[x2][y2];
					sum2 += beta_[x1][y1] + beta_[x1][y2] + beta_[x2][y1] + beta_[x2][y2];
				}
			}
//			printf("[%d][%d] sum1 %d; sum2 %d\n", i1, i2, sum1, sum2);
			sum += sum1 * beta[i1][i2];
			sum_ += sum2 * beta_[i1][i2];
		}
	}
//	printf("sum %f; sum_ %f\n", sum, sum_);
	
	pr11 = double(sum/900/4/l);
	pr_1_1 = double(sum_/900/4/l);
	pr1_1 = 1 - pr11 - pr_1_1;
	
	double h, term1, term2, term3;
	if (pr11)
		term1 = pr11 * log10(pr11);
	else
		term1 = 0;
	
	if(pr_1_1)
		term2 = pr_1_1 * log10(pr_1_1);
	else
		term2 = 0;

	if(pr1_1)
		term3 = pr1_1 * log10(pr1_1);
	else
		term3 = 0;
	
	h = - (term1 + term2 + term3);
	
//	printf("pr11 %f; pr_1_1 %f; pr1_1 %f; h %f\n",pr11, pr_1_1, pr1_1, h);
	return h;
}

double calHs(){
	int beta[SIZE][SIZE] = {0};
	double sum = 0;
	
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++){
			beta[i][j] = (state[i][j] + 1) / 2;
			sum += beta[i][j];
		}
	
	double pr1 = double(sum/900);
	double pr_1 = 1 - pr1;
	
	double Hs, t1, t2, t3;
	if (pr1)
		t1 = pr1 * log10(pr1);
	else
		t1 = 0;
	if (pr_1)
		t2 = pr_1 * log10(pr_1);
	else
		t2 = 0;

	Hs = -(t1 + t2);

	return Hs;
}
