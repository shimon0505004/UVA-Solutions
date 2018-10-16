#include<stdio.h>
#define maxn 5004
char prime[maxn]={0};
int main()
{
	int i,j,cases,n;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=(n>>1)+1;i<n;i++){
			if(!prime[i]){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
