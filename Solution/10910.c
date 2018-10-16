#include<stdio.h>
int main(){
	int C[70][70]={0},i,j;
	int cases,N,T,P;
	C[0][0]=1;
	for(i=1;i<70;i++){
		C[i][0]=1;
		for(j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&N,&T,&P);
		if(N*P>T){
			puts("0");
			continue;
		}
		printf("%d\n",C[N+T-N*P-1][T-N*P]);
	}
	return 0;
}
