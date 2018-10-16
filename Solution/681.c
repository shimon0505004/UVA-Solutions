#include<stdio.h>
struct POINT{
	int x,y;
};
int dis_sqr(struct POINT *p1,struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return x*x+y*y;
}
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.y-v1.y*v2.x;
}
int find_c_hull(struct POINT p[],int n,int c_hull[]){
	int i,start=0,now,next,check,count=0,cp;
	for(i=1;i<n;i++)
		if(p[i].y<p[start].y) start=i;
		else if(p[i].y==p[start].y&&p[i].x<p[start].x) start=i;
	now=start;
	do{
		c_hull[count++]=now;
		next=(now+1)%n;
		for(i=2;i<n;i++){
			check=(now+i)%n;
			cp=cross_product(&p[now],&p[next],&p[check]);
			if(cp<0) next=check;
			else if(cp==0&&dis_sqr(&p[now],&p[next])<dis_sqr(&p[now],&p[check])) next=check;
		}
		now=next;
	}while(p[next].x!=p[start].x||p[next].y!=p[start].y);
	return count;
}
int main(){
	int cases,N,i;
	struct POINT p[600];
	int c_hull[600],n_c_h;
	scanf("%d",&cases);
	printf("%d\n",cases);
	while(cases--){
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%*d");
		n_c_h=find_c_hull(p,N,c_hull);
		printf("%d\n",n_c_h+1);
		for(i=0;i<n_c_h;i++)
			printf("%d %d\n",p[c_hull[i]].x,p[c_hull[i]].y);
		printf("%d %d\n",p[c_hull[0]].x,p[c_hull[0]].y);
		if(cases) puts("-1");
	}
	return 0;
}
