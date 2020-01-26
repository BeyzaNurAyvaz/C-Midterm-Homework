#include<stdio.h>
#include<stdlib.h> 
#include<time.h> 
#define M 5
#define N 5
int main(){
	
	
	/*int f[M][N]={{105,102,100,97,14},
    		     {103,99,103,101,18},
		   	     {101,98,104,102,23},
		  	     {24,25,26,27,28},
		         {29,30,31,32,33}}; */
	//srand(time(0)); 	         
	int f[M][N]={0};
    
	for(int i=0;i<M;i++){ // random matris oluþturulmasý
    	printf("\n\n\n");
    	for(int j=0;j<N;j++){
    		f[i][j]=rand()%255;
    		printf("%d\t",f[i][j]);
		}
	}
	
	
	int v[3][3]={{0,-1,0}, 
				{-1,5,-1},
				{0,-1,0}};
	
	int g[M-2][N-2]={0}; 	
	
	int x=0,y;
	

	for(int i=1;i<M-1;i++){
	 y=0;
		for(int j=1;j<M-1;j++){
			
			g[x][y]= f[i-1][j-1]*v[0][0] + f[i-1][j]*v[0][1] + f[i-1][j+1]*v[0][2];          // satýrlar çok uzun olduðu için 
			g[x][y]= g[x][y] + f[i][j-1]*v[1][0] + f[i][j]*v[1][1] + f[i][j+1]*v[1][2];		 // iþlemi üç adýma böldüm
			g[x][y]= g[x][y] + f[i+1][j-1]*v[2][0] + f[i+1][j]*v[2][1] + f[i+1][j+1]*v[2][2];
			
			y++;
			//printf("%d",y);
		}
		x++;
		//printf("%d",x);
	}
	
	printf("\n\n\n**************************************");
	for(int i=0;i<x;i++){  
		printf("\n\n");
		for(int j=0;j<y;j++){
			printf("%d\t",g[i][j]);
		}
	}
	
}
