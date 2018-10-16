#include<stdio.h>
#include<math.h>
int main()
{
	double sqrtn,n;
	unsigned int test;
	while(1){
		scanf("%lf",&n);
		if(n==0.0) break;
		test=(unsigned int)sqrt(n);
		if(test==sqrt(n))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
