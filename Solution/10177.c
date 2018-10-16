#include<stdio.h>
int main()
{
	int n,i;
	long long S2,R2,S3,R3,S4,R4,temp;
	while(scanf("%d",&n)==1){
		temp=n*(n+1)/2;
		S2=n*(n+1)*(2*n+1)/6;
		R2=temp*temp-S2;
		S3=n*(n+1)/2*n*(n+1)/2;
		R3=temp*temp*temp-S3;
		for(i=1,S4=0;i<=n;i++) S4+=(i*i*i*i);
		R4=temp*temp*temp*temp-S4;
		printf("%lld %lld %lld %lld %lld %lld\n",S2,R2,S3,R3,S4,R4);
	}
	return 0;
}
