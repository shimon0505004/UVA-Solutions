#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))
#define sqr(x) ((x)*(x))
typedef struct POINT{
	double x,y,z;
}Point;
double dis(Point p1,Point p2){
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y)+sqr(p1.z-p2.z));
}
char isseen(Point p1,Point p2){
	Point O;
	double d12,d1O,d2O,theta;
	O.x=O.y=O.z=0;
	d12=dis(p1,p2),d1O=dis(p1,O),d2O=dis(p2,O);
	theta=acos((sqr(d12)+sqr(d2O)-sqr(d1O))/(2*d2O*d12));
	if(theta>pi/2) return 1;
	return 0;
}
int main(){
	int k,m,i,count;
	Point satel[105],trop;
	while(scanf("%d%d",&k,&m),k+m){
		for(i=0;i<k;i++)
			scanf("%lf%lf%lf",&satel[i].x,&satel[i].y,&satel[i].z);
		count=0;
		while(m--){
			scanf("%lf%lf%lf",&trop.x,&trop.y,&trop.z);
			for(i=0;i<k;i++)
				if(isseen(satel[i],trop)){
					count++;
					break;
				}
		}
		printf("%d\n",count);
	}
	return 0;
}
