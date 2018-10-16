#include<stdio.h>
#include<string.h>
int main(){
	int N,i;
	int count[10],t;
	unsigned long long fac[13],pow_10[13],result;
	fac[0]=pow_10[0]=1;
	for(i=1;i<13;i++) fac[i]=fac[i-1]*i,pow_10[i]=pow_10[i-1]*10;
	while(scanf("%d",&N),N){
		memset(count,0,sizeof(count));
		for(i=0;i<N;i++) scanf("%d",&t),count[t]++;
		result=0;
		for(i=1;i<10;i++)
			result+=count[i]*i;
		result*=fac[N-1];
		for(i=0;i<10;i++) result/=fac[count[i]];
		result*=(pow_10[N]-1)/9;
		printf("%llu\n",result);
	}
	return 0;
}
