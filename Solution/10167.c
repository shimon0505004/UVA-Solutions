#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct POINT{
	int x,y;
}Point;
int cross(const Point *p1,const Point *p2){
	return p1->x*p2->y-p1->y*p2->x;
}
typedef struct CAKE{
	Point pos;
	int c,countc;
}Strawberry;
int compar(const void *a,const void *b){
	Point *p1=&(((Strawberry *)a)->pos),*p2=&(((Strawberry *)b)->pos);
	if(atan2(p1->y,p1->x)>atan2(p2->y,p2->x)) return 1;
	return -1;
}
int main(){
	int N,i,j,total,t,count=0;
	Strawberry p[105];
	while(scanf("%d",&N),N){
		total=N<<1;
		for(i=0;i<total;i++){
			scanf("%d%d",&p[i].pos.x,&p[i].pos.y);
			p[i].c=p[i].countc=0;
		}
		qsort(p,total,sizeof(Strawberry),compar);
		for(i=0;i<total;i++)
			for(j=0;j<i;j++){
				t=cross(&(p[i].pos),&(p[j].pos));
				if(t>0) p[i].countc++,p[j].c++;
				else if(t<0) p[i].c++,p[j].countc++;
				else if(t==0)
					if(p[i].pos.x*p[j].pos.x+p[i].pos.y*p[j].pos.y>0)
						p[j].countc++,p[i].c++;
			}
		if(p[total-1].c==N-1&&p[0].countc==N-1)
			if(cross(&(p[total-1].pos),&(p[0].pos))==0)
				printf("%d %d\n",-p[total-1].pos.x,p[total-1].pos.y);
			else
				printf("%d %d\n",-(p[total-1].pos.y+p[0].pos.y),p[total-1].pos.x+p[0].pos.x);

		else
			for(i=0;i<total;i++)
				if(p[i].c==N-1&&p[i+1].countc==N-1){
					if(cross(&(p[i].pos),&(p[i+1].pos))==0)
						printf("%d %d\n",-p[i].pos.x,p[i].pos.y);
					else
						printf("%d %d\n",-(p[i].pos.y+p[i+1].pos.y),p[i].pos.x+p[i+1].pos.x);
					break;
				}
	}
	return 0;
}
