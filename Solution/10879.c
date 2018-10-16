#include<stdio.h>
#define maxn 3126
char prime[maxn]={0};
int primen[450],count=0;
char isprime(int n){
	int i;
	if(n<maxn) return prime[n];
	for(i=0;primen[i]*primen[i]<=n;i++)
		if(n%primen[i]==0) return 1;
	return 0;
}
int main()
{
	int i,j,count=0,N,K,flag;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&K);
		printf("Case #%d: %d",i,K);
		flag=0;
		for(j=0;j<count;j++)
			if(K%primen[j]==0){
				printf(" = %d * %d",primen[j],K/primen[j]);
				if(flag) break;
				if(K%(primen[j]*primen[j])==0){
					printf(" = %d * %d",primen[j]*primen[j],K/primen[j]/primen[j]);
					break;
				}
				flag=1;
			}
		puts("");
	}
	return 0;
}
