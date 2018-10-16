#include<stdio.h>
int main(){
	int a1,b1,c1,a2,b2,c2;
	while(scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2),a1||b1||c1||a2||b2||c2){
		if(a1*b2==a2*b1) puts("No fixed point exists.");
		else{
			int d,dx,dy;
			double x,y;
			d=a1*b2-a2*b1;
			dx=c1*b2-c2*b1;
			dy=a1*c2-a2*c1;
			if(dx==0) x=0;
			else x=(double)dx/d;
			if(dy==0) y=0;
			else y=(double)dy/d;
			printf("The fixed point is at %.2lf %.2lf.\n",x,y);
		}
	}
	return 0;
}
