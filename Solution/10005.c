#include<stdio.h>
#include<math.h>
#define SWAP(a,b) {double temp=a;a=b;b=temp;}
struct POINT{
	double x,y;
};
double dis(struct POINT *p1,struct POINT *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
double circleR(struct POINT *p1,struct POINT *p2,struct POINT *p3){
	struct POINT v1,v2;
	double area;
	double a=dis(p1,p2),b=dis(p2,p3),c=dis(p1,p3);
	if(b<c) SWAP(b,c);
	if(a<b) SWAP(a,b);
	v1.x=p2->x-p1->x,v1.y=p2->y-p1->y;
	v2.x=p3->x-p1->x,v2.y=p3->y-p1->y;
	if(b*b+c*c<a*a) return a/2;
	area=fabs(v1.x*v2.y-v1.y*v2.x)/2;
	return a*b*c/area/4.0;
}
char is_contain(struct POINT p[],int n,double r){
	int i,j,k;
	if(n==1) return 1;
	if(n==2) if(dis(&p[0],&p[1])>r*2) return 0;
	for(i=2;i<n;i++)
		for(j=1;j<i;j++)
			for(k=0;k<j;k++)
				if(circleR(&p[i],&p[j],&p[k])>r) return 0;
	return 1;
}
int main(){
	struct POINT p[105];
	double r;
	int n,i;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		scanf("%lf",&r);
		if(is_contain(p,n,r)) puts("The polygon can be packed in the circle.");
		else puts("There is no way of packing that polygon.");
	}
	return 0;
}
