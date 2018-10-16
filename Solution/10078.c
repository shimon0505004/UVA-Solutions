#include<stdio.h>
struct POINT{
	int x,y;
};
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.y-v1.y*v2.x;
}
char isconcave(struct POINT gallery[],int N,int cmp){
	int i;
	for(i=0;i<N-2;i++) if(cmp*cross_product(&gallery[i],&gallery[i+1],&gallery[i+2])<0) return 1;
	if(cmp*cross_product(&gallery[N-1],&gallery[0],&gallery[1])<0) return 1;
	return 0;
}
int main(){
	int N,i,cmp;
	struct POINT gallery[55];
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++) scanf("%d%d",&gallery[i].x,&gallery[i].y);
		if(cross_product(&gallery[N-2],&gallery[N-1],&gallery[0])<0) cmp=-1;
		else cmp=1;
		if(isconcave(gallery,N,cmp)) puts("Yes");
		else puts("No");
	}
	return 0;
}
