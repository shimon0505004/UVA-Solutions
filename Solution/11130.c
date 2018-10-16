#include<stdio.h>
#include<math.h>
#define EPS (1e-5)
#define pi 3.14159265358979323846
int main(){
	double a,b,v,A,s,d;
	while(scanf("%lf%lf%lf%lf%lf",&a,&b,&v,&A,&s),a>EPS){
		A=A/180*pi;
		d=v*s/2;
		printf("%d %d\n",(int)((d*cos(A)-a/2)/a+1),(int)((d*sin(A)-b/2)/b+1));
	}
	return 0;
}
