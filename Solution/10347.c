#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,area;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
		if(a<=0||b<=0||c<=0){
			printf("-1.000\n");
			continue;
		}
		if(a+b<=c||b+c<=a||a+c<=b)
			printf("-1.000\n");
		else{
			area=sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b))/3.0;
		/*if(area>0)*/
			printf("%.3lf\n",area);
/*		else
			printf("-1.000\n");*/
		}
	}
	return 0;
}
