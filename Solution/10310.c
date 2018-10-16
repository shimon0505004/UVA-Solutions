#include<stdio.h>
#include<math.h>
int main()
{
	int i,holes,flag;
	double gopherX,gopherY,dogX,dogY,holeX[1020],holeY[1020],gh2,dh2;
	while(scanf("%d%lf%lf%lf%lf",&holes,&gopherX,&gopherY,&dogX,&dogY)!=EOF){
		flag=-1;
		for(i=0;i<holes;i++){
			scanf("%lf%lf",&holeX[i],&holeY[i]);
			gh2=pow(holeX[i]-gopherX,2)+pow(holeY[i]-gopherY,2);
			dh2=pow(holeX[i]-dogX,2)+pow(holeY[i]-dogY,2);
			if(dh2>=4*gh2&&flag==-1)
				flag=i;
		}
		printf("The gopher can");
		if(flag==-1)
			printf("not escape.\n");
		else
			printf(" escape through the hole at (%.3lf,%.3lf).\n",holeX[flag],holeY[flag]);
	}
	return 0;
}
