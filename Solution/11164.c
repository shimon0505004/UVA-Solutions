#include<stdio.h>
#include<math.h>
#define EPS (1e-5)
int main(){
	double a,b,c,d;
	int cases;
	for(cases=1;scanf("%lf%lf%lf",&a,&b,&c),a>-EPS;cases++){
		printf("Set %d:\n",cases);
		if(fabs(b*b-a*c)<EPS) puts("Poor King!");
		else{
			d=a*c*(a+b*2+c)/(b*b-a*c);
			if(d<-EPS) puts("Poor King!");
			else printf("%.4lf\n",d);
		}
	}
	return 0;
}
