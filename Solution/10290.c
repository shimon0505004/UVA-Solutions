#include<stdio.h>
#include<string.h>
#define maxn 30000003
char prime[maxn]={0};
long long primen[1857860];
int main()
{
	int i,j,count=0;
	long long N;
	int expo[13],result;
	char isdivisor;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	while(scanf("%lld",&N)==1){
		if(N==0){
			printf("1\n");
			continue;
		}
		memset(expo,0,sizeof(expo));
		while(N%2==0) N>>=1;
		count=0;
		for(i=1;primen[i]*primen[i]<=N;i++){
			isdivisor=0;
			if(N%primen[i]==0) isdivisor=1;
			while(N%primen[i]==0) N/=primen[i],expo[count]++;
			if(isdivisor) count++;
		}
		for(i=0,result=1;i<count;i++)
			result*=expo[i]+1;
		if(N>1) result*=2;
		printf("%d\n",result);
	}
	return 0;
}
