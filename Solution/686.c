#include<stdio.h>
#define maxn 32770
int main()
{
	int i,j,n,answer,comb;
	char prime[maxn]={0};
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	while(1){
		scanf("%d",&n);
		if(n==4){
			printf("1\n");
			continue;
		}
		comb=0;
		if(!n)
			break;
		else
			for(i=3;i<=n/2;i++)
				if(prime[i]+prime[n-i]) continue;
				else
					comb++;
		printf("%d\n",comb);
	}
	return 0;
}
