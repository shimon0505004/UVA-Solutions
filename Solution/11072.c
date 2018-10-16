#include<stdio.h>
#include<stdlib.h>
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
int make_convex_hull(struct POINT set[],int p,int conv_hull[]){
	int i,start;
	int now,next,count=0,cp;
	for(start=i=0;i<p;i++)
		if(set[start].x>set[i].x) start=i;
		else if(set[start].x==set[i].x&&set[start].y>set[i].y) start=i;
	now=start;
	do{
		conv_hull[count++]=now;
		next=(now+1)%p;
		for(i=0;i<p;i++)
			if(i!=next&&i!=now){
				cp=cross_product(&set[now],&set[next],&set[i]);
				if(cp<0) next=i;
				else if(cp==0&&dis_sqr(&set[now],&set[i])>dis_sqr(&set[now],&set[next])) next=i;
			}
		now=next;
	}while(now!=start);
	return count;
}
int t_area(struct POINT *p,struct POINT set[],int conv_hull[],int n_c_h){
	int i,area=0;
	for(i=1;i<n_c_h;i++) area+=abs(cross_product(p,&set[conv_hull[i-1]],&set[conv_hull[i]]));
	area+=abs(cross_product(p,&set[conv_hull[n_c_h-1]],&set[conv_hull[0]]));
	return area;
}
int cal_area(struct POINT set[],int conv_hull[],int n_c_h){
	int area=0,i;
	for(i=1;i<n_c_h;i++)
		area+=set[conv_hull[i-1]].x*set[conv_hull[i]].y-set[conv_hull[i-1]].y*set[conv_hull[i]].x;
	area+=set[conv_hull[n_c_h-1]].x*set[conv_hull[0]].y-set[conv_hull[n_c_h-1]].y*set[conv_hull[0]].x;
	return area;
}
int main(){
	int p,r,i,n_c_h;
	struct POINT set[100005],testP;
	int conv_hull[100005],area;
	while(scanf("%d",&p)==1){
		for(i=0;i<p;i++) scanf("%d%d",&set[i].x,&set[i].y);
		scanf("%d",&r);
		n_c_h=make_convex_hull(set,p,conv_hull);
		area=cal_area(set,conv_hull,n_c_h);
		while(r--){
			scanf("%d%d",&testP.x,&testP.y);
			if(t_area(&testP,set,conv_hull,n_c_h)==area) puts("inside");
			else puts("outside");
		}
	}
	return 0;
}
