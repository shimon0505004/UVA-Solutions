#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
int main()
{
	double D,V,d;
	while(scanf("%lf%lf",&D,&V)==2&&(D+V)){
		d=pow(pow(D,3)-6.0*V/pi,1.0/3.0);
		printf("%.3lf\n",d);
	}
	return 0;
}
