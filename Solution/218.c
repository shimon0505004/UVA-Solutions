#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 1005
struct POINT{
	double x,y;
};
double dis(struct POINT *p1,struct POINT *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
double cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.y-v1.y*v2.x;
}
double inner_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.x+v1.y*v2.y;
}
int find_c_hull(struct POINT p[],int n,int c_hull[]){
	int i,start=0,now,next,check,count=0;
	double cp,ip;
	for(i=1;i<n;i++)
		if(p[i].y<p[start].y) start=i;
		else if(fabs(p[i].y-p[start].y)<1e-8&&p[i].x<p[start].x) start=i;
	now=start;
	do{
		c_hull[count++]=now;
		next=(now+1)%n;
		for(i=2;i<n;i++){
			check=(now+i)%n;
			cp=cross_product(&p[now],&p[next],&p[check]);
			ip=inner_product(&p[now],&p[next],&p[check]);
			if(cp>0) next=check;
			else if(cp>-1e-8&&ip>0&&dis(&p[now],&p[next])>dis(&p[now],&p[check]))
				next=check;
		}
		now=next;
	}while(next!=start);
	return count;
}
int main(){
	int cases,N,i;
	struct POINT p[SIZE];
	int c_hull[SIZE],n_c_h;
	double perimeter;
	for(cases=1;scanf("%d",&N),N;cases++){
		if(cases>1) puts("");
		for(i=0;i<N;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		n_c_h=find_c_hull(p,N,c_hull);
		printf("Region #%d:\n",cases);
		printf("(%.1lf,%.1lf)",p[c_hull[n_c_h-1]].x,p[c_hull[n_c_h-1]].y);
		perimeter=0;
		for(i=0;i<n_c_h-1;i++){
			printf("-(%.1lf,%.1lf)",p[c_hull[i]].x,p[c_hull[i]].y);
			perimeter+=dis(&p[c_hull[i]],&p[c_hull[i+1]]);
		}
		printf("-(%.1lf,%.1lf)",p[c_hull[n_c_h-1]].x,p[c_hull[n_c_h-1]].y);
		puts("");
		perimeter+=dis(&p[c_hull[n_c_h-1]],&p[c_hull[0]]);
		printf("Perimeter length = %.2lf\n",perimeter);
	}
	return 0;
}
