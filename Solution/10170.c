#include<stdio.h>
#include<math.h>
int main()
{
	double S,D;
	while(scanf("%lf%lf",&S,&D)==2)
		printf("%.0lf\n",ceil((sqrt(1+4*(S*S-S+2*D))-1)/2));
	return 0;
}
