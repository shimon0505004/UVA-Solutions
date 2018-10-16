#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
struct BODY{
	int cycle,dis;
	double angle,dis_sum;
	double x,y;
};
int main(){
	int n,T,i;
	struct BODY body[55];
	while(scanf("%d%d",&n,&T)==2){
		for(i=0;i<n;i++) scanf("%d%d",&body[i].dis,&body[i].cycle);
		body[0].angle=pi*2*T/body[0].cycle;
		body[0].dis_sum=body[0].dis;
		body[0].x=cos(body[0].angle)*body[0].dis;
		body[0].y=sin(body[0].angle)*body[0].dis;
		for(i=1;i<n;i++){
			body[i].angle=pi*2*T/body[i].cycle;
			body[i].x=body[i-1].x+cos(body[i].angle)*body[i].dis;
			body[i].y=body[i-1].y+sin(body[i].angle)*body[i].dis;
			body[i].dis_sum=sqrt(body[i].x*body[i].x+body[i].y*body[i].y);
		}
		printf("%.4lf",body[0].dis_sum);
		for(i=1;i<n;i++) printf(" %.4lf",body[i].dis_sum);
		puts("");
	}
	return 0;
}
