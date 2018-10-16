#include<stdio.h>
#include<math.h>
#define pi 2.0*acos(0.0)
int main()
{
	double r,I,E;
	int n,R;
	while(scanf("%d%d",&R,&n)!=EOF){
		if(n==1)
			printf("%.10lf %.10lf %.10lf\n",(double)R,0.0,0.0);
		else{
			r=R*sin(pi/n)/(1.0+sin(pi/n));
			I=n*((R-r)*r*cos(pi/n)-r*r*(pi-2.0*pi/n)/2.0);
			E=R*R*pi-I-n*r*r*pi;
			printf("%.10lf %.10lf %.10lf\n",r,I,E);
		}
	}
	return 0;
}
