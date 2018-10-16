#include<stdio.h>
#include<math.h>
#define eps 1e-6
#define min(x,y) ((x)<(y)?(x):(y))
int main(){
	double x,y,c,A,B,Ubound,Lbound,f;
	while(scanf("%lf%lf%lf",&x,&y,&c)==3){
		Ubound=min(x,y),Lbound=0;
		while(Ubound-Lbound>eps){
			f=(Ubound+Lbound)/2;
			A=x*x-f*f,B=y*y-f*f;
			if(sqrt(A*B)/(sqrt(A)+sqrt(B))<c) Ubound=f;
			else Lbound=f;
		}
		printf("%.3lf\n",f);
	}
	return 0;
}
