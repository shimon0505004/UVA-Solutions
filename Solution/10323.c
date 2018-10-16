#include<stdio.h>
int main()
{
	int input;
	long long fac[6]={40320LL,362880LL,3628800LL,39916800LL,479001600LL,6227020800LL};
	while(scanf("%d",&input)==1){
		if(input<0&&(input%2==0)) puts("Underflow!");
		else if(input<0&&(input%2==-1)) puts("Overflow!");
		else if(input<8) puts("Underflow!");
		else if(input>13) puts("Overflow!");
		else printf("%lld\n",fac[input-8]);
	}
	return 0;
}
