#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
int main()
{
	int nsided,n=0;
	double area,r2,rt2,official,spectator;
	while(1){
		n++;
		scanf("%d%lf",&nsided,&area);
		if(nsided<3)
			break;
		r2=2*area/sin(2*pi/nsided)/nsided;
		rt2=r2*pow(cos(pi/nsided),2);
		official=area-rt2*pi;
		spectator=r2*pi-area;
		printf("Case %d: %.5lf %.5lf\n",n,spectator,official);
	}
	return 0;
}
