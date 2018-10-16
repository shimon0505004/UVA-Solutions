#include<stdio.h>
#include<math.h>
int main()
{
	long long n,k,up,down,temp;
	double test;
	while(scanf("%lld",&n)!=EOF){
		test=(-1.0+sqrt(8*n+1))/2.0;
		k=floor(test);
		if(k!=test)
			k++;
		up=k*(k+1)/2-n+1;
		down=k+1-up;
		printf("%lld/%lld\n",up,down);
	}
	return 0;
}
