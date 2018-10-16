#include<stdio.h>
#include<math.h>
#define EPS 1e-6
int main(){
	int grid,skew,skew1,skew2,x,y;
	double s1,s2;
	while(scanf("%lf%lf",&s1,&s2)==2){
		if(s1<1||s2<1){
			puts("0 grid");
			continue;
		}
		grid=((int)s1)*((int)s2);
		y=(int)((s2-1)*2/sqrt(3))+1;
		x=(int)s1;
		if(s1-x+EPS>0.5) skew1=x*y;
		else skew1=x*y-y/2;
		y=(int)((s1-1)*2/sqrt(3))+1;
		x=(int)s2;
		if(s2-x+EPS>0.5) skew2=x*y;
		else skew2=x*y-y/2;
		if(skew1>skew2) skew=skew1;
		else skew=skew2;
		if(grid>=skew) printf("%d grid\n",grid);
		else printf("%d skew\n",skew);
	}
	return 0;
}
