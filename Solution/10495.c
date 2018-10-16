#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
int main(){
	double r,h,d1,A1,d2,A2;
	double theta;
	while(scanf("%lf%lf%lf%lf%lf%lf",&r,&h,&d1,&A1,&d2,&A2)==6){
		theta=fabs(A2-A1);
		if(theta>180) theta=360-theta;
		theta=theta/180*pi*r/sqrt(h*h+r*r);
		printf("%.2lf\n",sqrt(d1*d1+d2*d2-2*d1*d2*cos(theta)));
	}
	return 0;
}
