#include<stdio.h>
#include<math.h>
int main()
{
	int N,i=0;
	double r,d,h1;
	double h2,theta;
	scanf("%d",&N);
	while(i<N){
		scanf("%lf%lf%lf",&r,&d,&h1);
		theta=acos((r-d)/r);
		theta*=2;
		theta+=asin((r-h1)/r);
		h2=r-r*sin(theta);
		printf("Case %d: %.4lf\n",++i,h2);
	}
	return 0;
}
