#include<stdio.h>
#define SIZE 100005
int make_prime(int prime[]){
	char notPrime[SIZE]={0};
	int i,j,count=0;
	for(i=2;i<SIZE/2;i++){
		if(notPrime[i]) continue;
		prime[count++]=i;
		for(j=2;i*j<SIZE;j++)
			notPrime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++) if(notPrime[i]==0) prime[count++]=i;
	return count;
}
int main(){
	long long n,sum,b,t,count;
	int i;
	int prime[10000],n_prime;
	n_prime=make_prime(prime);
	while(scanf("%lld%lld",&n,&b),n|b){
		for(i=0,t=b;i<n_prime&&t!=prime[i];i++)
			if(t%prime[i]==0) t/=prime[i];
		sum=0;
		for(b=t;b<=n;b*=t){
			count=n/b;
			sum-=(count+1)*count/2*b;
			sum+=(n+1)*count;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
