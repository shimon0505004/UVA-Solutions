#include<stdio.h>
#define EPS 1e-6
typedef struct POINT{
	double x,y;
}Point;
typedef struct POINT_SET{
	Point p[105];
}PointSet;
double Area(Point *p0,Point *p1,Point *p2){
	double x1=p1->x-p0->x,x2=p2->x-p0->x,y1=p1->y-p0->y,y2=p2->y-p0->y;
	return (x1*y2-x2*y1)/2;
}
PointSet Polygon;
Point compare;
int direction(Point *pi,Point *pj,Point *pk){
	if((pk->x-pi->x)*(pj->y-pi->y)-(pk->y-pi->y)*(pj->x-pi->x)>0) return 1;
	return -1;
}
int compar(const void *a,const void *b){
	return direction(&compare,((Point *)a),((Point *)b));
}
int main(){
	int sides,i,miny;
	Point *p0,*p1,*p2,temp;
	double cx,cy,area,totarea,min;
	while(scanf("%d",&sides),sides>2){
		min=1e15;
		for(i=0;i<sides;i++){
			scanf("%lf%lf",&Polygon.p[i].x,&Polygon.p[i].y);
			if(Polygon.p[i].y<min) min=Polygon.p[i].y,miny=i;
		}
		temp=Polygon.p[0],Polygon.p[0]=Polygon.p[miny],Polygon.p[miny]=temp;
		compare=Polygon.p[0];
		qsort(Polygon.p+1,sides-1,sizeof(Point),compar);
		cx=cy=totarea=0;
		p0=&(Polygon.p[0]);
		for(i=1;i<sides-1;i++){
			p1=&(Polygon.p[i]),p2=&(Polygon.p[i+1]);
			area=Area(p0,p1,p2);
			totarea+=area;
			cx+=area*(p0->x+p1->x+p2->x)/3;
			cy+=area*(p0->y+p1->y+p2->y)/3;
		}
		cx/=totarea,cy/=totarea;
		printf("%.3lf %.3lf\n",cx+EPS,cy+EPS);
	}
	return 0;
}
