#include<stdio.h>
#include<math.h>
#define SIZE 105
#define g 9.8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define pi 3.14159265358979323846
struct BUILD{
	double d,h;
};
int main(){
	struct BUILD bld[SIZE];
	int n,i;
	double theta,d,v;
	while(scanf("%d",&n)==1){
		scanf("%lf%lf",&bld[0].h,&bld[0].d);
		for(i=1;i<n;i++)
			scanf("%lf%lf",&bld[i].h,&bld[i].d),bld[i].d+=bld[i-1].d;
		d=bld[n-1].d;
		theta=0;
		for(i=0;i<n-1;i++){
			theta=MAX(theta,atan(bld[i].h/bld[i].d/(1-bld[i].d/d)));
			theta=MAX(theta,atan(bld[i].h/bld[i-1].d/(1-bld[i-1].d/d)));
		}
		v=sqrt(g*d/sin(2*theta));
		printf("%.2lf %.2lf\n",theta*180/pi,v);
	}
	return 0;
}
