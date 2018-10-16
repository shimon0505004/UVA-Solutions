#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define sqr(x) ((x)*(x))
#define EPS 1e-7
struct POINT{
	long double x,y;
};
long double distance(struct POINT *p1,struct POINT *p2){
	long double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
char cross_circle(struct POINT *p1,struct POINT *p2,long double r){
	return fabs(p1->x*p2->y-p1->y*p2->x)/distance(p1,p2)+EPS<r;
}
long double inner_product(struct POINT *p1,struct POINT *p2){
	return p1->x*p2->x+p1->y*p2->y;
}
char is_obtuse_triangle(struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1=*p1,v2.x=p1->x-p2->x,v2.y=p1->y-p2->y;
	if(inner_product(&v1,&v2)+EPS<0) return 1;
	v1=*p2,v2.x=p2->x-p1->x,v2.y=p2->y-p1->y;
	if(inner_product(&v1,&v2)+EPS<0) return 1;
	return 0;
}
long double myacos(long double val){
	if(val<-1) return acos(-1);
	if(val>1) return acos(1);
	return acos(val);
}
int main(){
	int N;
	struct POINT p1,p2,origin;
	long double r;
	long double d1,d2;
	long double dis,theta1,theta2,theta;
	scanf("%d",&N);
	origin.x=origin.y=0;
	while(N--){
		scanf("%LF%LF%LF%LF%LF",&p1.x,&p1.y,&p2.x,&p2.y,&r);
		if(p1.x==p2.x&&p1.y==p2.y) dis=0;
		else if(cross_circle(&p1,&p2,r)==0)
			dis=distance(&p1,&p2);
		else if(is_obtuse_triangle(&p1,&p2))
			dis=distance(&p1,&p2);
		else{
			d1=distance(&origin,&p1),d2=distance(&origin,&p2);
			dis=sqrt((d1+r)*(d1-r))+sqrt((d2+r)*(d2-r));
			theta1=myacos(r/d1);
			theta2=myacos(r/d2);
			theta=inner_product(&p1,&p2)/d1/d2;
			theta=myacos(theta);
			dis+=r*(theta-theta1-theta2);
		}
		if(fabs(dis)<EPS) dis=0;
		printf("%.3LF\n",dis);
	}
	return 0;
}
