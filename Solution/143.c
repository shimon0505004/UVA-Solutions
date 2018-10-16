#include<stdio.h>
#include<math.h>
#define EPS 1e-8
struct POINT{
	double x,y;
};
double part(struct POINT *p1,struct POINT *p2,double x){
	if(fabs(p2->x-p1->x)<EPS) return p2->y;
	return p1->y+(x-p1->x)/(p2->x-p1->x)*(p2->y-p1->y);
}
int main(){
	struct POINT p1,p2,p3;
	double Ubound,Lbound;
	int i,answer,from,to;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y),p1.x+p1.y+p2.x+p2.y+p3.x+p3.y>EPS){
		answer=0;
		if(p1.x>p2.x){struct POINT temp=p1;p1=p2,p2=temp;};
		if(p2.x>p3.x){struct POINT temp=p2;p2=p3,p3=temp;};
		if(p1.x>p2.x){struct POINT temp=p1;p1=p2,p2=temp;};
		from=(int)ceil(p1.x-EPS);
		if(from<1) from=1;
		to=(int)floor(p2.x-EPS);
		if(to>99) to=99;
		for(i=from;i<=to;i++){
			Ubound=part(&p1,&p2,(double)i);
			Lbound=part(&p1,&p3,(double)i);
			if(Ubound<Lbound){double temp=Ubound;Ubound=Lbound,Lbound=temp;}
			if(Ubound>99) Ubound=99;
			if(Lbound<1) Lbound=1;
			answer+=(int)ceil(Ubound+EPS)-(int)floor(Lbound-EPS)-1;
		}
		from=(int)floor(p3.x+EPS);
		if(from>99) from=99;
		to=(int)ceil(p2.x-EPS);
		if(to<1) to=1;
		for(i=from;i>=to;i--){
			Ubound=part(&p3,&p2,(double)i);
			Lbound=part(&p3,&p1,(double)i);
			if(Ubound<Lbound){double temp=Ubound;Ubound=Lbound,Lbound=temp;}
			if(Ubound>99) Ubound=99;
			if(Lbound<1) Lbound=1;
			answer+=(int)ceil(Ubound+EPS)-(int)floor(Lbound-EPS)-1;
		}
		printf("%4d\n",answer);
	}
	return 0;
}
