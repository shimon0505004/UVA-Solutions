#include<stdio.h>
#include<math.h>
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	int N,i,flag,M;
	double a;
	double x,y;
	while(scanf("%d%lf",&N,&a)&&(N+a)){
		M=0;
		for(i=0;i<N;i++){
			flag=0;
			scanf("%lf%lf",&x,&y);
			if(dis(x,y,0.0,0.0)>a) flag++;
			if(dis(x,y,0.0,a)>a) flag++;
			if(dis(x,y,a,0.0)>a) flag++;
			if(dis(x,y,a,a)>a) flag++;
			if(!flag) M++;
		}
		printf("%.5lf\n",((double)M/N)*a*a);
	}
	return 0;
}
