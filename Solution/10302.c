#include<stdio.h>
int main()
{
	long long result,n;
	while(scanf("%lld",&n)!=EOF){
		result=n * n * (n + 1) * (n + 1) /4;
		printf("%lld\n",result);
	}
	return 0;
}
