#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS (1e-8)
#define pi 3.14159265358979323846
typedef struct Complex{
	double real;
	double imag;
}C;
typedef struct polar{
	double theta;
	double r;
}P;
int compar(const void *a,const void *b){
	C *c1=(C *)a,*c2=(C *)b;
	if(fabs(c1->real-c2->real)>EPS){
		if(c1->real<c2->real) return 1;
		return -1;
	}
	if(c1->imag>c2->imag) return -1;
	return 1;
}
double Round(double n){
	if(fabs(n)<0.0005) return 1e-4;
	return n;
}
int main(){
	double r,theta;
	int n,i,cases;
	C c,ans[101];
	P p;
	for(cases=1;scanf("%lf%lf%*c%d",&c.real,&c.imag,&n)==3;cases++){
		p.r=sqrt(c.real*c.real+c.imag*c.imag);
		p.theta=atan2(c.imag,c.real);
		p.r=pow(p.r,1.0/n);
		for(i=0;i<n;i++){
			theta=(p.theta+pi*2*i)/n;
			ans[i].real=p.r*cos(theta);
			ans[i].imag=p.r*sin(theta);
		}
		qsort(ans,n,sizeof(C),compar);
		printf("Case %d:\n",cases);
		for(i=0;i<n;i++){
			printf("%.3lf",Round(ans[i].real));
			printf("%+.3lfi\n",Round(ans[i].imag));
		}
		puts("");
	}
	return 0;
}
