#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
int main()
{
	double radius,r1,r2,r3,r4;
	while(scanf("%lf",&radius)!=EOF){
		r1=radius*cos(pi/6);
		r2=radius*(cos(pi/6)/(1+cos(pi/6)));
		r3=radius*cos(pi/6)/2;
		r4=radius*sqrt(7)*cos(pi/6)/(2*sqrt(3)+sqrt(7));

		printf("%.10lf %.10lf %.10lf %.10lf\n",r1,r2,r3,r4);
	}
	return 0;
}
