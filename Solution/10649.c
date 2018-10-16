#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
int main()
{
	double d,s,theta,result;
	while(scanf("%lf%lf",&d,&s)==2&&(d+s)){
		theta=asin(s*sqrt(2)/d);
		if(s*s>(d*d/2))
			printf("INCORRECT INFORMATION !!!\n");
		else{
			theta=pi/4.0-theta;
			result=d*cos(theta)-s;
			printf("%.6lf\n",result);
		}
	}
	return 0;
}
