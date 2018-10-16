#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
#define R_SUN (432000.0)
#define R_PLANET (3950.0)
#define AU (92900000.0)
int main(){
	double sec;
	double theta_sun_rise,theta,dis,angle;
	theta_sun_rise=atan(R_SUN/AU)+acos(R_PLANET/sqrt(R_SUN*R_SUN+AU*AU));
	while(scanf("%lf",&sec)==1){
		if(sec<1e-4) sec=1e-4;
		theta=theta_sun_rise-(sec/86400)*2*pi;
		dis=(R_PLANET-AU*cos(theta))/sin(theta);
		if(dis<-R_SUN) puts("1.000000");
		else{
			angle=acos(dis/R_SUN);
			printf("%.6lf\n",(angle-sin(angle*2)/2)/pi);
		}
	}
	return 0;
}
