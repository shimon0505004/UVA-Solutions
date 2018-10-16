#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
int cp(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	int x1=p1->x-p0->x,y1=p1->y-p0->y,x2=p2->x-p0->x,y2=p2->y-p0->y;
	return x1*y2-x2*y1;
}
int compar(const void *a,const void *b){
	struct POINT *l1=(struct POINT *)a,*l2=(struct POINT *)b;
	if(l1[0].y!=l2[0].y) return l2[0].y-l1[0].y;
	if(l1[1].x>l1[0].x&&l2[1].x>l2[0].x) return l2[0].x-l1[0].x;
	if(l1[1].x<l1[0].x&&l2[1].x<l2[0].x) return l1[0].x-l2[0].x;
	return 0;
}
int main(){
	int cases,n,s,i,j;
	struct POINT line[100][2],cur;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d%d%d",&line[i][0].x,&line[i][0].y,&line[i][1].x,&line[i][1].y);
			if(line[i][0].y<line[i][1].y){
				struct POINT tmp=line[i][0];
				line[i][0]=line[i][1],line[i][1]=tmp;
			}
		}
		qsort(line,n,sizeof(struct POINT[2]),compar);
		scanf("%d",&s);
		for(i=0;i<s;i++){
			scanf("%d%d",&cur.x,&cur.y);
			for(j=0;j<n;j++)
				if((line[j][0].x-cur.x)*(line[j][1].x-cur.x)<0&&cp(&line[j][0],&cur,&line[j][1])*(line[j][0].x-line[j][1].x)>0)
					cur=line[j][1];
			printf("%d\n",cur.x);
		}
		if(cases) puts("");
	}
	return 0;
}
