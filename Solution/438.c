#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
double distance(double,double,double,double);
int main()
{
	double ax,ay,bx,by,cx,cy,ab,bc,ca,area,r,s;
	while(scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy)!=EOF){
		ab=distance(ax,ay,bx,by);
		bc=distance(bx,by,cx,cy);
		ca=distance(cx,cy,ax,ay);
		s=(ab+bc+ca)/2.0;
		area=sqrt(s*(s-ab)*(s-bc)*(s-ca));
		r=ab*bc*ca/(4.0*area);
		printf("%.2lf\n",2*pi*r);
	}
	return 0;
}
double distance(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
