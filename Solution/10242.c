#include<stdio.h>
int main()
{
	int i;
	double L1x[3],L1y[3],L2x[3],L2y[3];
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&L1x[0],&L1y[0],&L1x[1],&L1y[1],&L2x[0],&L2y[0],&L2x[1],&L2y[1])!=EOF){
		if(L1x[0]==L2x[0] && L1y[0]==L2y[0])
			printf("%.3lf %.3lf\n",L1x[1]+L2x[1]-L1x[0],L1y[1]+L2y[1]-L1y[0]);
		else if(L1x[0]==L2x[1] && L1y[0]==L2y[1])
			printf("%.3lf %.3lf\n",L1x[1]+L2x[0]-L1x[0],L1y[1]+L2y[0]-L1y[0]);
		else if(L1x[1]==L2x[0] && L1y[1]==L2y[0])
			printf("%.3lf %.3lf\n",L1x[0]+L2x[1]-L1x[1],L1y[0]+L2y[1]-L1y[1]);
		else if(L1x[1]==L2x[1] && L1y[1]==L2y[1])
			printf("%.3lf %.3lf\n",L1x[0]+L2x[0]-L1x[1],L1y[0]+L2y[0]-L1y[1]);
		getchar();
				
	}
	return 0;
}
