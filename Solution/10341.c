#include<stdio.h>
#include<math.h>
double p,q,r,s,t,u;
double function(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
double bsearch(double lbound,double ubound){
	double mid=(ubound+lbound)/2,test;
	if(fabs(ubound-lbound)<1e-8) return ubound;
	test=function(mid);
	if(test>0) return bsearch(lbound,mid);
	if(test<0) return bsearch(mid,ubound);
}
int main(){
	double result;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6){
		if(function(1)>function(0)) result=bsearch(0,1);
		else result=bsearch(1,0);
		if(fabs(function(result))<1e-3) printf("%.4lf\n",result);
		else puts("No solution");
	}
	return 0;
}
