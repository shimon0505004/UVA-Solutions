#include<stdio.h>
#include<math.h>
struct POINT{
	int x,y;
};
double dis(const struct POINT *p1,const struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
void caltoCartesian(const int n,struct POINT *p){
	int k=(int)((sqrt(1+2*n)-1)/2);
	int rest=n-2*k*(k+1),check;
	if(rest==0){
		p->x=-k,p->y=0;
		return;
	}
	k++;
	if(rest<=k){
		p->x=-k+rest,p->y=rest;
		return;
	}
	rest-=k;
	if(rest<=k){
		p->x=rest,p->y=k-rest;
		return;
	}
	rest-=k;
	if(rest<=k){
		p->x=k-rest,p->y=-rest;
		return;
	}
	rest-=k;
	p->x=-rest,p->y=-k+rest;
	return;
}
int main(){
	int a,b;
	struct POINT p1,p2;
	while(scanf("%d%d",&a,&b),a+b>=0){
		caltoCartesian(a,&p1);
		caltoCartesian(b,&p2);
		printf("%.2lf\n",dis(&p1,&p2));
	}
	return 0;
}
