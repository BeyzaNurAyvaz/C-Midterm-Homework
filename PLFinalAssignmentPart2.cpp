#include<stdio.h>
#include<stdlib.h> 
#include<time.h> 
#define M 5
#define N 5
int main(){

    srand(time(0)); 
    int f[M][N]={0};
    for(int i=0;i<M;i++){ // random matris oluþturulmasý
    	printf("\n\n\n");
    	for(int j=0;j<N;j++){
    		f[i][j]=rand()%255;
    		printf("%d\t",f[i][j]);
		}
		
	}

	int f2[M+2][N+2]={0}; // 0lardan oluþan büyütülmüþ matris
	
	for(int i=1;i<M+1;i++){ // f2nin içine f in kopyalanmasý
		for(int j=1;j<N+1;j++){
			f2[i][j] = f[i-1][j-1];
		//	printf("%d",f2[i][j]);
		}
	}
	
/*	for(int i=0;i<7;i++){ // f2nin içini basan kod
		printf("\n\n\n");
		for(int j=0;j<7;j++){
			printf("%d\t",f2[i][j]);
	}
	*/

	int v[3][3]={{0,-1,0},
				{-1,5,-1},
				{0,-1,0}};
	
	int g[5][5]={0};
	int x=0,y; 
	

	for(int i=1;i<M+1;i++){ 
	 y=0; 
		for(int j=1;j<N+1;j++){
			
			g[x][y]= f2[i-1][j-1]*v[0][0] + f2[i-1][j]*v[0][1] + f2[i-1][j+1]*v[0][2];           
			g[x][y]+=f2[i][j-1]*v[1][0] + f2[i][j]*v[1][1] + f2[i][j+1]*v[1][2];	
			g[x][y]+=f2[i+1][j-1]*v[2][0] + f2[i+1][j]*v[2][1] + f2[i+1][j+1]*v[2][2];
			
			y++;
		}
		x++;
	}

	printf("\n\n**********************************");
	for(int i=0;i<x;i++){
		printf("\n\n\n");
		for(int j=0;j<y;j++){
			printf("%d\t",g[i][j]);
		}
	}
	

   
}
  
 
