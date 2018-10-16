#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
struct POINT{
	double x,y;
};
double det(double a,double b,double c,double d){
	return a*d-b*c;
}
double dis(struct POINT *p1,struct POINT *p2){
	double x=p2->x-p1->x,y=p2->y-p1->y;
	return sqrt(x*x+y*y);
}
int main(){
	int N,i,cases;
	struct POINT p[3],m1,m2,v1,v2,c,U,L,arg;
	double t,delta,deg;
	for(cases=1;scanf("%d",&N),N;cases++){
		scanf("%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y);
		m1.x=(p[0].x+p[1].x)/2,m1.y=(p[0].y+p[1].y)/2;
		m2.x=(p[0].x+p[2].x)/2,m2.y=(p[0].y+p[2].y)/2;
		v1.y=p[1].x-p[0].x,v1.x=p[0].y-p[1].y;
		v2.y=p[2].x-p[0].x,v2.x=p[0].y-p[2].y;
		delta=det(v1.x,v2.x,v1.y,v2.y);
		t=det(m2.x-m1.x,v2.x,m2.y-m1.y,v2.y)/delta;
		c.x=m1.x+t*v1.x,c.y=m1.y+t*v1.y;
		deg=pi*2/N;
		U.x=U.y=-1e10,L.x=L.y=1e10;
		arg.x=p[0].x-c.x,arg.y=p[0].y-c.y;
		for(i=0;i<N;i++){
			struct POINT now;
			now.x=arg.x*cos(deg*i)-arg.y*sin(deg*i)+c.x;
			now.y=arg.y*cos(deg*i)+arg.x*sin(deg*i)+c.y;
			U.x=MAX(U.x,now.x),U.y=MAX(U.y,now.y);
			L.x=MIN(L.x,now.x),L.y=MIN(L.y,now.y);
		}
		printf("Polygon %d: %.3lf\n",cases,(U.x-L.x)*(U.y-L.y));
	}
	return 0;
}
