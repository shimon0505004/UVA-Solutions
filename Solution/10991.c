#include<stdio.h>
#include<math.h>
int main(){
	int cases;
	double R1,R2,R3,a,b,c,A,B,C,G,Area;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf%lf%lf",&R1,&R2,&R3);
		a=R1+R2,b=R2+R3,c=R1+R3;
		A=acos((c*c+b*b-a*a)/(c*b*2));
		B=acos((a*a+c*c-b*b)/(a*c*2));
		C=acos((a*a+b*b-c*c)/(a*b*2));
		Area=sqrt((a+b+c)/2*(a+b-c)/2*(a-b+c)/2*(-a+b+c)/2);
		G=Area-R1*R1*B/2-R2*R2*C/2-R3*R3*A/2;
		printf("%.6lf\n",G);
	}
	return 0;
}
