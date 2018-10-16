#include<stdio.h>
#include<string.h>
#define maxn 1000001
int main()
{
	int i,j,N,t;
	int factors[maxn]={0};
	for(i=2;i<maxn;i++){
		if(factors[i]==0) factors[i]=1;
		for(j=2;(t=i*j)<maxn&&j<=i;j++){
			if(factors[t]) continue;
			factors[t]=factors[j]+factors[i];
		}
	}
	for(i=3;i<maxn;i++) factors[i]+=factors[i-1];
	while(scanf("%d",&N)==1)
		printf("%d\n",factors[N]);
	return 0;
}
