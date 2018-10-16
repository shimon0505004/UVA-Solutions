#include<stdio.h>
#include<math.h>
#define EPS 1e-8
#define PI (acos(-1))
struct VECTOR{
	double x,y;
};
int main(){
	int N;
	double P,U,V,L,C,T,theta;
	struct VECTOR cheetah,prey,meet,Vu,CP,Vv;
	double a,b,c,delta;
	scanf("%d",&N);
	while(N--){
		scanf("%lf%lf%lf%lf",&cheetah.x,&cheetah.y,&prey.x,&prey.y);
		scanf("%lf%lf%lf%lf",&P,&U,&V,&L);
		theta=P*PI/180,CP.x=prey.x-cheetah.x,CP.y=prey.y-cheetah.y;
		Vu.x=U*cos(theta),Vu.y=U*sin(theta);
		a=U*U-V*V;
		b=(Vu.x*CP.x+Vu.y*CP.y)*2;
		c=CP.x*CP.x+CP.y*CP.y;
		delta=b*b-4*a*c;
		if(fabs(a)<EPS) T=-c/b;
		else if(delta<0) T=-1;
		else if(a>0) T=(-b+sqrt(delta))/(a*2);
		else if(b>sqrt(delta)) T=(-b+sqrt(delta))/(a*2);
		else T=(-b-sqrt(delta))/(a*2);
		meet.x=prey.x+T*Vu.x,meet.y=prey.y+T*Vu.y;
		Vv.x=meet.x-cheetah.x,Vv.y=meet.y-cheetah.y;
		C=acos(Vv.x/sqrt(Vv.x*Vv.x+Vv.y*Vv.y));
		if(Vv.y<0) C=2*PI-C;
		C=C/PI*180;
		if(T<0||T>L) puts("sorry, buddy");
		else printf("%.2lf %.2lf %.2lf %.2lf\n",C,T,meet.x,meet.y);
	}
	return 0;
}
