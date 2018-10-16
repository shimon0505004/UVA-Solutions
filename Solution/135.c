#include<stdio.h>
#include<stdlib.h>
void printAnswer(int n,char **matrix[]){
	int i,j;
	int col=n*n-n+1;
	for(i=0;i<col;i++){
		for(j=0;j<col;j++)
			if(matrix[n][i][j]){
				printf("%d",++j);
				break;
			}
		for(;j<col;j++)
			if(matrix[n][i][j]) printf(" %d",j+1);
		puts("");
	}
}
void makeMatrix(char **matrix[]){
	char prime[32]={
		1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,
		1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
	int i,col,j,k,l,shift,p;
	int field[32][32];
	for(i=0;i<32;i++)
		for(j=0;j<32;j++)
			field[i][j]=i*j;
	for(i=1;i<=32;i++){
		p=i-1;
		if(prime[p]){
			col=i*i-i+1;
			matrix[i][0][0]=1;
			for(j=1;j<col;j++)
				matrix[i][(j-1)/p][j]=matrix[i][j][(j-1)/p]=1;
			for(j=0;j<p;j++)
				for(k=0;k<p;k++){
					shift=field[j][k]%p;
					for(l=0;l<p;l++)
						matrix[i][i+j*p+l][i+k*p+(l+shift)%p]=1;
				}
		}
	}

}
int main(){
	int n,col,i,j;
	char **matrix[35],start=0;
	for(i=1;i<=32;i++){
		col=i*i-i+1;
		matrix[i]=(char **)calloc(col,sizeof(char *));
		for(j=0;j<col;j++)
			matrix[i][j]=(char *)calloc(col,sizeof(char));
	}
	makeMatrix(matrix);
	while(scanf("%d",&n)==1){
		if(start) puts("");
		else start=1;
		printAnswer(n,matrix);
	}
	return 0;
}
