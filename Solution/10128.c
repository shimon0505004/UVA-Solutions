#include<stdio.h>
int main(){
	const int fac[14]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,1932053504};
	long long Q[15][15]={0},result;
	int C[15][15]={0};
	int i,j,k,cases,N,P,R,tot;
	C[1][0]=C[1][1]=1;
	for(i=2;i<15;i++)
		for(j=i;j>=i/2;j--)
			C[i][i-j]=C[i][j]=C[i-1][j]+C[i-1][j-1];
	Q[0][0]=1;
	for(i=1;i<15;i++)
		for(j=1;j<=i;j++)
			for(k=0;k<i;k++)
				Q[i][j]+=Q[k][j-1]*fac[i-1]/fac[k];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&N,&P,&R);
		result=0;
		for(i=0;i<N;i++)
			result+=Q[i][P-1]*Q[N-i-1][R-1]*C[N-1][i];
		printf("%lld\n",result);
	}
	return 0;
}
