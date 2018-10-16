#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
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
		}
		now=next;
	}while(next!=start);
	return count;
}
int main(){
	int cases,N,i,t_area,b_area;
	struct POINT p[105];
	int c_hull[105],n_c_h;
	for(cases=1;scanf("%d",&N),N;cases++){
		for(i=0;i<N;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		n_c_h=find_c_hull(p,N,c_hull);
		t_area=b_area=0;
		for(i=0;i<N;i++){
			int next=(i+1)%N;
			t_area+=p[i].x*p[next].y-p[next].x*p[i].y;
		}
		t_area=abs(t_area);
		for(i=0;i<n_c_h;i++){
			int next=(i+1)%n_c_h;
			b_area+=p[c_hull[i]].x*p[c_hull[next]].y-p[c_hull[next]].x*p[c_hull[i]].y;
		}
		t_area=abs(t_area),b_area=abs(b_area);
		printf("Tile #%d\n",cases);
		printf("Wasted Space = %.2lf %%\n",(double)(b_area-t_area)*100/b_area);
		puts("");
	}
	return 0;
}
