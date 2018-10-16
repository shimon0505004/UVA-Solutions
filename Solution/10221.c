#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
int main()
{
	double s,a,r=6440.0,arc,chord;
	char unit[5];
	while(scanf("%lf%lf%s",&s,&a,&unit)==3){
		s+=r;
		if(*unit=='m')
			a/=60;
		if(a>180)
			a=360-a;
		a*=pi/180;
		arc=s*a;
		chord=2*s*sin(a/2);
		printf("%.6lf %.6lf\n",arc,chord);
	}
	return 0;
}
