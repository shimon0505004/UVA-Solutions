#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
struct POINT{
	int x,y;
};
double len(struct POINT *a,struct POINT *b){
	int x=b->x-a->x,y=b->y-a->y;
	return sqrt(x*x+y*y);
}
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	int x1=p1->x-p0->x,y1=p1->y-p0->y,x2=p2->x-p0->x,y2=p2->y-p0->y;
	return x1*y2-x2*y1;
}
int main(){
	int N,Q,i,cases;
	struct POINT p[20005],A,B;
	int map[80005],*shmap=map+40000,dis[20005];
	scanf("%d%d",&N,&Q);
	for(i=0;i<N;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(cases=1;cases<=Q;cases++){
		int ans=0,min=40000,t,mid;
		memset(map,0,sizeof(map));
		scanf("%d%d%d%d",&A.x,&A.y,&B.x,&B.y);
		for(i=0;i<N;i++){
			int cp=cross_product(&A,&p[i],&B);
			dis[i]=cp;
			shmap[cp]++;
			min=MIN(min,cp);
		}
		for(mid=min-1,t=0;t<N/2;t+=shmap[++mid]);
		for(i=0;i<N;i++) ans+=abs(dis[i]-mid);
		printf("Case %d: %d\n",cases,(int)((double)ans/len(&A,&B)+0.5));
	}
	return 0;
}
