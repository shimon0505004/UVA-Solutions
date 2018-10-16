#include<stdio.h>
#include<math.h>
#define EPS (1e-8)
struct POINT{
	double x,y;
};
double dis(struct POINT *p1,struct POINT *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
double r(double input){
	if(fabs(input)<0.0005) return 0;
	return input;
}
int main(){
	struct POINT p1,p2;
	double r1,r2,d;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&r1,&p2.x,&p2.y,&r2)==6){
		if(fabs(p1.x-p2.x)<EPS&&fabs(p1.y-p2.y)<EPS&&fabs(r1-r2)<EPS){
			if(r1<EPS) printf("(%.3lf,%.3lf)\n",r(p1.x),r(p1.y));
			else puts("THE CIRCLES ARE THE SAME");
			continue;
		}
		d=dis(&p1,&p2);
		if(d+EPS<fabs(r1-r2)||d>r1+r2+EPS){
			puts("NO INTERSECTION");
			continue;
		}
		if(fabs(d-fabs(r1-r2))<EPS){
			double t;
			if(r1<r2){
				t=r2/d;
				printf("(%.3lf,%.3lf)\n",r(p2.x+t*(p1.x-p2.x)),r(p2.y+t*(p1.y-p2.y)));
			}else{
				t=r1/d;
				printf("(%.3lf,%.3lf)\n",r(p1.x+t*(p2.x-p1.x)),r(p1.y+t*(p2.y-p1.y)));
			}
		}else if(fabs(d-(r1+r2))<EPS)
			printf("(%.3lf,%.3lf)\n",r((r2*p1.x+r1*p2.x)/(r1+r2)),r((r2*p1.y+r1*p2.y)/(r1+r2)));
		else{
			struct POINT itrs1,itrs2,mid,v,v_;
			double h,l;
			v.x=(p2.x-p1.x)*((d*d+r1*r1-r2*r2)/(2*d*d));
			v.y=(p2.y-p1.y)*((d*d+r1*r1-r2*r2)/(2*d*d));
			h=sqrt(r1*r1-(v.x*v.x+v.y*v.y));
			l=sqrt(v.x*v.x+v.y*v.y);
			mid.x=p1.x+v.x,mid.y=p1.y+v.y;
			v_.x=v.y,v_.y=-v.x;
			itrs1.x=mid.x+v_.x*h/l,itrs1.y=mid.y+v_.y*h/l;
			itrs2.x=mid.x-v_.x*h/l,itrs2.y=mid.y-v_.y*h/l;
			if(itrs1.x>itrs2.x){
				struct POINT temp=itrs1;
				itrs1=itrs2,itrs2=temp;
			}else if(fabs(itrs1.x-itrs2.x)<EPS&&itrs1.y>itrs2.y){
				struct POINT temp=itrs1;
				itrs1=itrs2,itrs2=temp;
			}
			printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n",r(itrs1.x),r(itrs1.y),r(itrs2.x),r(itrs2.y));
		}
	}
	return 0;
}
