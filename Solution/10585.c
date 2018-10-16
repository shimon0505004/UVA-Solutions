#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
int compar(const void *a,const void *b){
	struct POINT *p1=(struct POINT *)a,*p2=(struct POINT *)b;
	if(p1->x!=p2->x) return p1->x-p2->x;
	return p1->y-p2->y;
}
int main(){
	int cases,n,i;
	struct POINT p[10005],middle;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		qsort(p,n,sizeof(struct POINT),compar);
		middle.x=p[0].x+p[n-1].x,middle.y=p[0].y+p[n-1].y;
		for(i=1;i<n-1;i++)
			if(p[i].x+p[n-1-i].x!=middle.x||p[i].y+p[n-1-i].y!=middle.y) break;
		if(i<n-1) puts("no");
		else puts("yes");
	}
	return 0;
}
