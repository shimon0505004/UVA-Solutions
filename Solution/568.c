#include<stdio.h>
int countfac(int n)
{
	int result,rest,restfac,i;
	if(n==0||n==1) return 1;
	result=6;
	rest=n%10;
	for(i=1,restfac=1;i<=rest;i++)
		restfac*=i;
	n/=10;
	n<<=1;
	if(rest>=5){
		n++;
		restfac/=5;
	}
	restfac%=10;
	result*=countfac(n);
	n%=4;
	result<<=(4-n);
	result*=restfac;
	result%=10;
	return result;
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
		printf("%5d -> %d\n",n,countfac(n));
	return 0;
}
