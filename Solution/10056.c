#include<stdio.h>
#include<math.h>
int main()
{
	double p,a;
	int n,times,i,I;
	scanf("%d",&times);
	for(i=0;i<times;i++){
		scanf("%d%lf%d",&n,&p,&I);
		a=pow(1-p,I-1)*p/(1-pow(1-p,n));
		if(p==0.0){
			printf("0.0000\n");
			continue;
		}
		printf("%.4lf\n",a);
	}
	return 0;
}
