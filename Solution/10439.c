#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
typedef struct POINT{
	double x,y;
}Point;
double distance(Point *p1,Point *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
void calSide(Point p[],double side[]){
	side[0]=distance(p+1,p+2);
	side[1]=distance(p+0,p+2);
	side[2]=distance(p+0,p+1);
}
void calDeg(double side[],double deg[]){
	deg[0]=acos((side[1]*side[1]+side[2]*side[2]-side[0]*side[0])/(2*side[1]*side[2]))*2;
	deg[1]=acos((side[0]*side[0]+side[2]*side[2]-side[1]*side[1])/(2*side[0]*side[2]))*2;
	deg[2]=acos((side[1]*side[1]+side[0]*side[0]-side[2]*side[2])/(2*side[0]*side[1]))*2;
}
double GCD(double d1,double d2){
	double temp;
	while(fmod(d1,d2)>1e-4)
		temp=d1,d1=d2,d2=fmod(temp,d2);
	return d2;
}
int main(){
	int cases,i;
	Point p[3];
	double deg[3],side[3],gcd;
	scanf("%d",&cases);
	while(cases--){
		for(i=0;i<3;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		calSide(p,side),calDeg(side,deg);
		gcd=GCD(deg[0],GCD(deg[1],deg[2]));
		printf("%.0lf\n",2*pi/gcd);
	}
	return 0;
}
