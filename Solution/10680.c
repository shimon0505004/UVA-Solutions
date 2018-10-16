#include<stdio.h>
#define max 1000005
int main()
{
	int N[max]={0},i,j,prime,n;
	char isprime[max]={0};
	isprime[0]=isprime[1]=1;
	for(i=2;i<max;i++)
		if(!isprime[i]){
			for(j=2;i*j<max;j++)
				isprime[i*j]=1;
			for(prime=1;(double)max/prime>i;prime*=i)
				N[prime*i]=i;
		}
	N[0]=1;
	for(i=1;i<max;i++){
		if(N[i]){
			if(N[i]%5)
				N[i]=N[i-1]*N[i];
			else
				N[i]=N[i-1]*8;
			N[i]%=10;
		}
		else
			N[i]=N[i-1];
	}
	while(scanf("%d",&n)&&n)
		printf("%d\n",N[n]);
	return 0;
}
