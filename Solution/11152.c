#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
int main(){
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)==3){
		double s=(a+b+c)/2,area=sqrt(s*(s-a)*(s-b)*(s-c)),R=a*b*c/4/area,r=area/s;
		printf("%.4lf %.4lf %.4lf\n",R*R*pi-area,area-r*r*pi,r*r*pi);
	}
	return 0;
}
