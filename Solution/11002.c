#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int table[35][35];
	int N,i,j,col,row;
	int MAX;
	char ele[35][35][3005];
	while(scanf("%d",&N),N){
		memset(ele,0,sizeof(ele));
		for(i=0;i<N;i++)
			for(row=i,col=0;row>=0;col++,row--)
				scanf("%d",&table[row][col]);
		for(i=1;i<N;i++)
			for(row=N-1,col=i;col<N;col++,row--)
				scanf("%d",&table[row][col]);
		ele[0][0][abs(table[0][0])]=1;
		MAX=(2*N-1)*50+1;
		for(i=0;i<N;i++){
			for(row=i,col=0;row>=0;col++,row--){
				for(j=0;j<MAX;j++){
					if(ele[row][col][j]==0) continue;
					if(col<N-1){
						ele[row][col+1][abs(j-table[row][col+1])]=1;
						ele[row][col+1][abs(j+table[row][col+1])]=1;
					}
					if(row<N-1){
						ele[row+1][col][abs(j+table[row+1][col])]=1;
						ele[row+1][col][abs(j-table[row+1][col])]=1;
					}
				}
			}
		}
		for(i=1;i<N;i++){
			for(row=N-1,col=i;col<N;col++,row--){
				for(j=0;j<MAX;j++){
					if(ele[row][col][j]==0) continue;
					if(col<N-1){
						ele[row][col+1][abs(j-table[row][col+1])]=1;
						ele[row][col+1][abs(j+table[row][col+1])]=1;
					}
					if(row<N-1){
						ele[row+1][col][abs(j+table[row+1][col])]=1;
						ele[row+1][col][abs(j-table[row+1][col])]=1;
					}
				}
			}
		}
		for(i=0;i<MAX;i++)
			if(ele[N-1][N-1][i]){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
