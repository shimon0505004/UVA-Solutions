#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct POINT{
	double x,y;
};
double inner_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	double x1=p1->x-p0->x,y1=p1->y-p0->y;
	double x2=p2->x-p0->x,y2=p2->y-p0->y;
	return x1*x2+y1*y2;
}
double cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	double x1=p1->x-p0->x,y1=p1->y-p0->y;
	double x2=p2->x-p0->x,y2=p2->y-p0->y;
	return x1*y2-x2*y1;
}
double dis(struct POINT *p1,struct POINT *p2){
	return sqrt(inner_product(p1,p2,p2));
}
double cal_dis(struct POINT *M,struct POINT *p0,struct POINT *p1,struct POINT *t){
	double in1=inner_product(p0,p1,M),in2=inner_product(p1,p0,M);
	double r,len=dis(p0,p1),l1=dis(p0,M),l2=dis(p1,M);
	if(in1>0&&in2>0){
		r=in1/len/len;
		t->x=p0->x+r*(p1->x-p0->x);
		t->y=p0->y+r*(p1->y-p0->y);
		return fabs(cross_product(p0,p1,M))/len;
	}
	if(l1<l2){
		*t=*p0;
		return l1;
	}
	*t=*p1;
	return l2;
}
int main(){
	struct POINT p[10005],M;
	int N,i;
	while(scanf("%lf%lf",&M.x,&M.y)==2){
		struct POINT ans;
		double min;
		scanf("%d",&N);
		for(i=0;i<N+1;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		min=1e10;
		for(i=0;i<N;i++){
			struct POINT t;
			double d=cal_dis(&M,&p[i],&p[i+1],&t);
			if(d<min) min=d,ans=t;
		}
		printf("%.4lf\n%.4lf\n",ans.x,ans.y);
	}
	return 0;
}
