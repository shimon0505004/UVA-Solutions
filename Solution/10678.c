#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
int main()
{
	int N,i;
	double D,L,area;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%lf%lf",&D,&L);
		area=L/4.0*sqrt(pow(L,2)-pow(D,2))*pi;
		printf("%.3lf\n",area);
	}
	return 0;
}
