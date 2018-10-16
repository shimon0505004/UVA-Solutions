#include<stdio.h>
#include<math.h>
#define sqr(a) ((a)*(a))
double cal_r6(double s){
	double x,y;
	double U=2*s,L=s,r=(U+L)/2;
	while(U-L>1e-9*r){
		x=(sqrt(2*r*r-s*s)-s)/2;
		y=sqrt(r*r-sqr(2*s-x))-x;
		if(sqr((s-x-y)*sqrt(2)+s*3/2)+sqr(s/2)<sqr(r)) U=r;
		else L=r;
		r=(U+L)/2;
	}
	return r;
}
int main(){
	int cases;
	double side;
	double r[7];
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf",&side);
		r[1]=side/sqrt(2);
		r[2]=side*sqrt(5)/2;
		r[3]=side*5*sqrt(17)/16;
		r[4]=side*sqrt(2);
		r[5]=side*sqrt(10)/2;
		r[6]=cal_r6(side);
		printf("%.11lf %.11lf %.11lf %.11lf %.11lf %.11lf\n",r[1],r[2],r[3],r[4],r[5],r[6]);
	}
	return 0;
}
