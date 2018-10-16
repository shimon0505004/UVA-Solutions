#include<stdio.h>
#include<math.h>
int main()
{
	int N;
	double r,s,t;
	scanf("%d",&N);
	while(N--){
		scanf("%lf",&r);
		t=(3*sqrt(3)+3)*r*2/3;
		printf("%.10lf %.10lf\n",t+sqrt(33)*r*2/3,t+(3+sqrt(24))*r*2/3);
	}
	return 0;
}
