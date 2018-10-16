#include<stdio.h>
#define maxn 1000000
int main()
{
	int i,j,n,answer;
	char prime[maxn]={0};
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		else
			for(i=3;i<=n/2;i++)
				if(prime[i]+prime[n-i]) continue;
				else{
					printf("%d = %d + %d\n",n,i,n-i);
					break;
				}
	}
	return 0;
}
