#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
struct POINT{
	int x,y;
};
struct POINT n_to_p(int n){
	struct POINT p;
	int sqrt_n=(int)sqrt(n+0.5);
	int d;
	sqrt_n=(sqrt_n-1)/2*2+1;
	d=n-sqrt_n*sqrt_n;
	p.x=sqrt_n/2,p.y=sqrt_n/2;
	if(d>0) p.x++,d--;
	if(d>0) p.y-=MIN(d,sqrt_n),d-=sqrt_n;
	if(d>0) p.x-=MIN(sqrt_n+1,d),d-=sqrt_n+1;
	if(d>0) p.y+=MIN(sqrt_n+1,d),d-=sqrt_n+1;
	if(d>0) p.x+=MIN(sqrt_n+1,d),d-=sqrt_n+1;
	return p;
}
int p_to_n(int x,int y){
	int n,n_circle=MAX(abs(x),abs(y)),d;
	d=n_circle*2-1;
	n=d*d;
	if(x==n_circle&&y<n_circle) n+=n_circle-y;
	else if(y==-n_circle) n+=d+1+n_circle-x;
	else if(x==-n_circle) n+=2*(d+1)+y+n_circle;
	else n+=3*(d+1)+x+n_circle;
	return n;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		struct POINT p=n_to_p(n);
		printf("%d;%d;%d;\n",p_to_n(p.x-1,p.y+1),p_to_n(p.x,p.y+1),p_to_n(p.x+1,p.y+1));
		printf("%d;%d;%d;\n",p_to_n(p.x-1,p.y),p_to_n(p.x,p.y),p_to_n(p.x+1,p.y));
		printf("%d;%d;%d;\n",p_to_n(p.x-1,p.y-1),p_to_n(p.x,p.y-1),p_to_n(p.x+1,p.y-1));
	}
	return 0;
}
