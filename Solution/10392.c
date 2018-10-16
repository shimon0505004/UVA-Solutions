#include<stdio.h>
#define maxn 1000000
char prime[maxn]={0};
int primen[78498],count=0;
char isprime(int n){
	int i;
	if(n<maxn) return prime[n];
	for(i=0;primen[i]*primen[i]<=n;i++)
		if(n%primen[i]==0) return 1;
	return 0;
}
int main()
{
	int i,j,count=0;
	long long N;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	while(scanf("%lld",&N),N>0){
		for(i=0;primen[i]*primen[i]<=N&&i<78498;i++){
			for(;N%primen[i]==0;N/=primen[i])
				printf("    %d\n",primen[i]);
		}
		if(N>1) printf("    %lld\n",N);
		puts("");
	}
	return 0;
}
