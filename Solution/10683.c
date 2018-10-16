#include<stdio.h>
int main()
{
	int h,m,s,c;
	double result;
	char results[10];
	while(scanf("%2d%2d%2d%2d",&h,&m,&s,&c)==4){
		result=(double)(h*60*60*100+m*60*100+s*100+c)/8640000;
		sprintf(results,"%.9lf\n",result);
		printf("%.7s\n",results+2);
	}
	return 0;
}
