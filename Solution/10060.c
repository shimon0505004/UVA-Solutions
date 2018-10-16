#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
#define EPS 1e-6
struct POINT{
	double x,y;
};
int main(){
	int N,n,i;
	double thick,volume,t,R,T;
	struct POINT p[100];
	while(scanf("%d",&N),N){
		volume=0;
		while(N--){
			scanf("%lf",&thick);
			scanf("%lf%lf",&p[0].x,&p[0].y);
			for(n=1;scanf("%lf%lf",&p[n].x,&p[n].y),fabs(p[n].x-p[0].x)>EPS||fabs(p[n].y-p[0].y)>EPS;n++);
			t=0;
			for(i=0;i<n;i++)
				t+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
			volume+=fabs(t)*thick/2;
		}
		scanf("%lf%lf",&R,&T);
		printf("%d\n",(int)(volume/(R*R*pi*T)));
	}
	return 0;
}
