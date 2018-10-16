#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double r,area,pi;
	pi=2*acos(0);
	while(scanf("%lf%d",&r,&n)!=EOF){
		area=(double)1/2*pow(r,2)*sin(2*(double)pi/n)*n;
		printf("%.3lf\n",area);
	}
	return 0;
}
