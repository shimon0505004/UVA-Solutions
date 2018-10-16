#include<stdio.h>
typedef struct POINT{
	int x,y;
}Point;
typedef struct POINT_SET{
	Point p[105];
	int points;
	double area;
}PointSet;
double Area(PointSet *S){
	int i;
	double result=S->p[S->points-1].x*S->p[0].y-S->p[0].x*S->p[S->points-1].y;
	for(i=1;i<S->points;i++)
		result+=S->p[i-1].x*S->p[i].y-S->p[i].x*S->p[i-1].y;
	return result/2;
}
PointSet sites[25];
int n_stack;
char visit[105];
Point compare;
void push(int index,int i){
	sites[index].p[n_stack++]=sites[index].p[i];
}
void pop(){
	n_stack--;
}
Point *NEXT_TO_TOP(int index){
	return &(sites[index].p[n_stack-2]);
}
Point *TOP(int index){
	return &(sites[index].p[n_stack-1]);
}
int direction(Point *pi,Point *pj,Point *pk){
	return (pk->x-pi->x)*(pj->y-pi->y)-(pk->y-pi->y)*(pj->x-pi->x);
}
char inside(PointSet *S,Point *p){
	int i,n=S->points;
	if(direction(&(S->p[n-1]),p,&(S->p[0]))<0) return 0;
	for(i=1;i<n;i++)
		if(direction(&(S->p[i-1]),p,&(S->p[i]))<0) return 0;
	return 1;
}
int compar(const void *a,const void *b){
	return direction(&compare,((Point *)a),((Point *)b));
}
int main(){
	int builds,i,kingd,min,miny,locs;
	double result;
	Point temp,p;
	for(kingd=0;scanf("%d",&builds),builds>-1;kingd++){
		min=505;
		for(i=0;i<builds;i++){
			scanf("%d%d",&sites[kingd].p[i].x,&sites[kingd].p[i].y);
			if(sites[kingd].p[i].y<min) min=sites[kingd].p[i].y,miny=i;
			else if(sites[kingd].p[i].y==min&&sites[kingd].p[i].x<sites[kingd].p[miny].x) 
				miny=i;
		}
		locs=i;
		temp=sites[kingd].p[0],sites[kingd].p[0]=sites[kingd].p[miny],sites[kingd].p[miny]=temp;
		compare=sites[kingd].p[0];
		qsort(sites[kingd].p+1,locs-1,sizeof(Point),compar);
		n_stack=3;
		for(i=3;i<locs;i++){
			while(direction(NEXT_TO_TOP(kingd),TOP(kingd),&(sites[kingd].p[i]))>0) pop();
			push(kingd,i);
		}
		sites[kingd].points=n_stack;
		sites[kingd].area=Area(&sites[kingd]);
	}
	result=0;
	memset(visit,0,kingd*sizeof(char));
	while(scanf("%d%d",&p.x,&p.y)==2)
		for(i=0;i<kingd;i++){
			if(inside(&(sites[i]),&p)&&visit[i]==0){
				result+=sites[i].area;
				visit[i]=1;
			}
		}
	printf("%.2lf\n",result);
	return 0;
}
