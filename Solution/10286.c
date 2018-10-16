#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
int main()
{
	double sidePen,sideSqu;
	while(scanf("%lf",&sidePen)!=EOF){
		sideSqu=sin(108*pi/180)/sin(63*pi/180)*sidePen;
		printf("%.10lf\n",sideSqu);
	}
	return 0;
}
