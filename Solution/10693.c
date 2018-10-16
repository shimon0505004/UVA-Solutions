#include<stdio.h>
#include<math.h>
int main()
{
	double f,L,v,n;
	while(scanf("%lf%lf",&L,&f)==2&&(L+f)){
		v=sqrt(2*f*L);
		n=v/(2*L)*3600;
		printf("%.8lf %.8lf\n",v,n);
	}
	return 0;
}
