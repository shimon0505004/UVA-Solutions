#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
int main()
{
	double UP,D,L,B,P,DOWN,V,result;
	int cases=0;
	double getV;
	const double gravity=32.2*12;
	while(1){
		scanf("%lf",&UP);
		if(UP<0.0000001) break;
		if(cases) printf("\n");
		scanf("%lf%lf%lf%lf%lf%lf",&D,&L,&B,&P,&DOWN,&V);
		printf("Scenario %d:\n",++cases);
		printf("     %-18s%8.2lf sec\n","up hill",UP);
		printf("     %-18s%8.2lf in\n","well diameter",D);
		printf("     %-18s%8.2lf in\n","water level",L);
		printf("     %-18s%8.2lf cu ft\n","bucket volume",B);
		printf("     %-18s%8.2lf in/sec\n","bucket ascent rate",P);
		printf("     %-18s%8.2lf sec\n","down hill",DOWN);
		printf("     %-18s%8.2lf cu ft\n","required volume",V);
		getV=0;
		result=0;
		while(getV+0.0000001<V*12*12*12){
			result+=UP;
			result+=sqrt(2.0*L/gravity);
			result+=L/P;
			L+=B*12*12*12/(D*D*pi/4.0);
			result+=DOWN;
			getV+=B*12*12*12;
		}
		printf("     %-18s%8.2lf sec\n","TIME REQUIRED",result);
	}
	return 0;
}
