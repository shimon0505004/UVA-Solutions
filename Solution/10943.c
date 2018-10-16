#include<stdio.h>
int main(){
	int C[205][205]={0},i,j,N,K;
	C[0][0]=1;
	for(i=1;i<205;i++){
		C[i][0]=1;
		for(j=i;j>=1;j--)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%1000000;
	}
	while(scanf("%d%d",&N,&K),N+K)
		printf("%d\n",C[N+K-1][N]);
	return 0;
}
