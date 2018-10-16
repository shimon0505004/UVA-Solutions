#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	char prime[32]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
	char baseprime[32]={0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1};
	long long perfect[32];
	for(i=2;i<32;i++)
		perfect[i]=(long long)pow(2,i-1)*(pow(2,i)-1);
	while(scanf("%d",&n)==1&&n){
		if(baseprime[n])
			printf("Perfect: %lld!\n",perfect[n]);
		else
			if(prime[n])
				puts("Given number is prime. But, NO perfect number is available.");
			else
				puts("Given number is NOT prime! NO perfect number is available.");
	}
	return 0;
}
