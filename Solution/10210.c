#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	double x1,x2,y1,y2,deg1,deg2,MN,result;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&deg1,&deg2)==6){
		deg1/=180;
		deg1*=pi;
		deg2/=180;
		deg2*=pi;
		MN=dis(x1,y1,x2,y2);
		result=MN/tan(deg1);
		result+=MN/tan(deg2);
		printf("%.3lf\n",result);
	}
	return 0;
}
