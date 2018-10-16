#include<stdio.h>
#define maxn 10100
char prime[maxn]={0};
int primen[1240],count=0;
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
	while(scanf("%d",&N)==1){
		printf("%d is ",N);
		if(N<5)
			puts("not the sum of two primes!");
		else if(N%2==0){
			for(i=N/2-1;i>2;i--)
				if(isprime(i)+isprime(N-i)) continue;
				else{
					printf("the sum of %d and %d.\n",i,N-i);
					break;
				}
			if(i==2) puts("not the sum of two primes!");
		}else
			if(isprime(N-2)==0)
				printf("the sum of 2 and %d.\n",N-2);
			else puts("not the sum of two primes!");
	}
	return 0;
}
