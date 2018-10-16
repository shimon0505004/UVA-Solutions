#include<stdio.h>
#include<math.h>
int main()
{
	double pi=2.0*acos(0.0),a;
	while(scanf("%lf",&a)!=EOF){
		printf("%.3lf %.3lf %.3lf\n",(1-sqrt(3)+pi/3)*pow(a,2),4*(sqrt(3)/2+pi/12-1)*pow(a,2),4*(1-sqrt(3)/4-pi/6)*pow(a,2));
	}
	return 0;
}
