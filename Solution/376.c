#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
int main(){
	double a,b,theta,s1,s2;
	int cases=0;
	puts("Case    A      B    THETA  # of    Side   Side");
	puts(" #     side   side  (deg)  Triags    1      2");
	while(scanf("%lf%lf%lf",&a,&b,&theta),a+b+theta>1e-6){
		printf("%4d%7.2lf%7.2lf%7.2lf",++cases,a,b,theta);
		theta=theta/180*pi;
		if(a+1e-6>b&&2*theta+1e-6>pi)
			printf("%6d\n",0);
		else if(a/b*sin(theta)+1e-6>1)
			printf("%6d\n",0);
		else if(theta<1e-6)
			printf("%6d  %7.2lf%7.2lf\n",2,a+b,fabs(a-b));
		else if(a>b){
			s1=b/sin(theta)*sin(pi-theta-asin(a/b*sin(theta)));
			s2=b/sin(theta)*sin(asin(a/b*sin(theta))-theta);
			printf("%6d  %7.2lf%7.2lf\n",2,s1,s2);
		}else{
			s1=b/sin(theta)*sin(pi-theta-asin(a/b*sin(theta)));
			printf("%6d  %7.2lf\n",1,s1);
		}
		
	}
	printf("\nEND OF REPORT for %d cases\n",cases);
	return 0;
}
