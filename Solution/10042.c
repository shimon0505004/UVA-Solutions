#include<stdio.h>
#define maxn 31630
char prime[maxn]={0};
int primen[3402];
char isprime(int n){
	int i;
	if(n<maxn) return prime[n];
	for(i=0;primen[i]*primen[i]<=n;i++)
		if(n%primen[i]==0) return 1;
	return 0;
}
int countdigits(int n){
	int result=0;
	while(n) result+=n%10,n/=10;
	return result;
}
int factordigits(int n){
	int result=0,i;
	for(i=0;primen[i]*primen[i]<=n;i++)
		while(n%primen[i]==0) result+=countdigits(primen[i]),n/=primen[i];
	if(n>1) result+=countdigits(n);
	return result;
}
int main()
{
	int i,j,count=0;
	int cases,input;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&input);
		for(i=input+1;;i++){
			if(!isprime(i)) continue;
			if(countdigits(i)==factordigits(i)){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
