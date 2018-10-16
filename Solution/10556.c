#include<stdio.h>
struct POINT{
	int x,y;
};
int CrossProduct(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT a,b;
	int CP;
	a.x=p1->x-p0->x,a.y=p1->y-p0->y;
	b.x=p2->x-p0->x,b.y=p2->y-p0->y;
	CP=a.x*b.y-a.y*b.x;
	if(CP>0) return 1;
	if(CP<0) return -1;
	return 0;
}
int InnerProduct(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT a,b;
	a.x=p1->x-p0->x,a.y=p1->y-p0->y;
	b.x=p2->x-p0->x,b.y=p2->y-p0->y;
	return a.x*b.x+a.y*b.y;
}
int SqarDis(struct POINT *p1,struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return x*x+y*y;
}
int main(){
	struct POINT f1[15],f2[15];
	int i,N,A,B;
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++) scanf("%d%d",&f1[i].x,&f1[i].y);
		for(i=0;i<N;i++) scanf("%d%d",&f2[i].x,&f2[i].y);
		A=SqarDis(&f1[0],&f1[1]);
		B=SqarDis(&f2[0],&f2[1]);
		for(i=1;i<N;i++)
			if(SqarDis(&f1[i-1],&f1[i])*B!=SqarDis(&f2[i-1],&f2[i])*A) break;
		if(i<N){
			puts("dissimilar");
			continue;
		}
		for(i=1;i<N-1;i++)
			if(CrossProduct(&f1[i],&f1[i-1],&f1[i+1])!=CrossProduct(&f2[i],&f2[i-1],&f2[i+1])) break;
			else if(InnerProduct(&f1[i],&f1[i-1],&f1[i+1])*B!=InnerProduct(&f2[i],&f2[i-1],&f2[i+1])*A) break;
		if(i<N-1){
			puts("dissimilar");
			continue;
		}
		puts("similar");
	}
	return 0;
}
