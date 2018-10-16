#include<stdio.h>
#include<math.h>
int main()
{
	double v,u,diff,d;
	int cases,i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%lf%lf%lf",&d,&v,&u);
		printf("Case %d: ",i+1);
		if(v==0||u<=v){
			printf("can't determine\n");
		}
		else{
			diff=d/sqrt(u*u-v*v)-d/u;
			printf("%.3lf\n",diff);
		}
	}
	return 0;
}
