#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
#define EPS 1e-3
double part(double R,double r){
	double theta=acos((R*R*2-r*r)/(R*R*2));
	return ((pi-theta)*r*r/2+R*R*(theta-sin(theta)))/(R*R*pi);
}
int main(){
	int cases;
	double R,P,r,U,L;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf%lf",&R,&P);
		U=R*2,L=0;
		while(U-L>EPS){
			r=(U+L)/2;
			if(part(R,r)>P) U=r;
			else L=r;
		}
		printf("R = %.0lf, P = %.2lf, Rope = %.2lf\n",R+EPS,P,r);
		if(cases) puts("");
	}
	return 0;
}
