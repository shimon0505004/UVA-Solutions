#include<stdio.h>
#define maxn 1015
char prime[maxn]={0};
int primen[200],count=0;
char isprime(int n){
	int i;
	if(n<maxn) return prime[n];
	for(i=0;primen[i]*primen[i]<=n;i++)
		if(n%primen[i]==0) return 1;
	return 0;
}
int main()
{
	int i,j,N,answer,count=0;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	while(scanf("%d",&N),N){
		printf("%d:\n",N);
		if(N==4) puts("2+2");
		else if(N%2==0){
			for(i=3;i<=N/2;i++)
				if(isprime(i)+isprime(N-i)) continue;
				else{
					printf("%d+%d\n",i,N-i);
					break;
				}
		}else
			if(isprime(N-2)==0)
				printf("2+%d\n",N-2);
			else puts("NO WAY!");
	}
	return 0;
}
