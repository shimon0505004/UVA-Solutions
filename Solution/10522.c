#include<stdio.h>
#include<math.h>
int main()
{
	int invalidcases;
	double ha,hb,hc;
	scanf("%d",&invalidcases);
	while(invalidcases){
		scanf("%lf%lf%lf",&ha,&hb,&hc);
		ha=1.0/ha,hb=1.0/hb,hc=1.0/hc;
		if(ha+hb>hc&&fabs(ha-hb)<hc)
			printf("%.3lf\n",1.0/sqrt((ha+hb+hc)*(ha+hb-hc)*(ha-hb+hc)*(-ha+hb+hc)));
		else{
			printf("These are invalid inputs!\n");
			invalidcases--;
		}
	}
	return 0;
}
