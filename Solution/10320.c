#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
#define circle(r) ((r)*(r)*pi)
int main()
{
	double l,w,R;
	double area,theta,diag;
	while(scanf("%lf%lf%lf",&l,&w,&R)==3){
		area=0;
		area+=circle(R)*3.0/4;
		if(R<=l+w){
			if(R>l)
				area+=circle(R-l)/4;
			if(R>w)
				area+=circle(R-w)/4;
		}else{
			diag=sqrt(l*l+w*w);
			theta=acos(((R-l)*(R-l)+diag*diag-(R-w)*(R-w))/(2*(R-l)*diag));
			theta=pi/2-(theta-atan(l/w));
			area+=(R-l)*(R-l)*theta/2;
			area+=(R-l)*cos(theta)*w/2;
			theta=acos(((R-w)*(R-w)+diag*diag-(R-l)*(R-l))/(2*(R-w)*diag));
			theta=pi/2-(theta-atan(w/l));
			area+=(R-w)*(R-w)*theta/2;
			area+=(R-w)*cos(theta)*l/2;
		}
		printf("%.10lf\n",area);
	}
	return 0;
}
