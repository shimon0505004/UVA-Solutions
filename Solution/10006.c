#include<stdio.h>
#include<math.h>
#define Ubound 65050
char isprime[Ubound]={0};
unsigned BigMod(unsigned,unsigned,unsigned);
int main()
{
	unsigned n,i,j;
	isprime[0]=isprime[1]=1;
	for(i=2;i<=Ubound/2;i++)
		if(!isprime[i])
			for(j=2;i*j<=Ubound;j++)
				isprime[i*j]=1;
	while(scanf("%u",&n)==1&&n){
		if(isprime[n]){
			for(i=2;i<n;i++)
				if(BigMod(i,n,n)!=i)
					break;
			if(i==n)
				printf("The number %u is a Carmichael number.\n",n);
			else
				printf("%u is normal.\n",n);
		}
		else
			printf("%u is normal.\n",n);
	}
	return 0;
}
unsigned BigMod(unsigned B,unsigned P,unsigned M)
{
	unsigned temp;
	if(P==1)
		return B;
	else if(!(P%2)){
		temp=BigMod(B,P/2,M);
		return (temp*temp)%M;
	}
	else
		return (B*BigMod(B,P-1,M))%M;
}
