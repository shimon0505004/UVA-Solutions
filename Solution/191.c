#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef struct POINT{
	int x;
	int y;
}Point;
Point p[2];
typedef struct LINE{
	Point p1;
	Point p2;
}Line;
Line l,templ;
int Cross(Point p1,Point p2){
	return p1.x*p2.y-p2.x*p1.y;
}
int Dir(Point p1,Point p2,Point p3){
	Point tp1,tp2;
	tp1.x=p3.x-p1.x,tp1.y=p3.y-p1.y;
	tp2.x=p2.x-p1.x,tp2.y=p2.y-p1.y;
	return Cross(tp1,tp2);
}
int Between(Point p1,Point p2,Point p3){
	if(min(p1.x,p2.x)<=p3.x&&p3.x<=max(p1.x,p2.x)&&min(p1.y,p2.y)<=p3.y&&p3.y<=max(p1.y,p2.y))
		return 1;
	return 0;
}
int Intersect(Line L1,Line L2){
	int d1=Dir(L2.p1,L2.p2,L1.p1);
	int d2=Dir(L2.p1,L2.p2,L1.p2);
	int d3=Dir(L1.p1,L1.p2,L2.p1);
	int d4=Dir(L1.p1,L1.p2,L2.p2);
	if(d1*d2<0&&d3*d4<0) return 1;
	if(d1==0&&Between(L2.p1,L2.p2,L1.p1)) return 1;
	if(d2==0&&Between(L2.p1,L2.p2,L1.p2)) return 1;
	if(d3==0&&Between(L1.p1,L1.p2,L2.p1)) return 1;
	if(d4==0&&Between(L1.p1,L1.p2,L2.p2)) return 1;
	return 0;
}
void initial(){
	templ.p1=p[0];
	templ.p2=p[1];
}
int check(){
	if(Intersect(l,templ)){
		puts("T");
		return 1;
	}
	return 0;
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d%d",&l.p1.x,&l.p1.y,&l.p2.x,&l.p2.y);
		scanf("%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y);
		if(Between(p[0],p[1],l.p1)||Between(p[0],p[1],l.p2)){
			puts("T");
			continue;
		}
		initial();
		templ.p2.x=p[0].x;
		if(check()) continue;
		initial();
		templ.p2.y=p[0].y;
		if(check()) continue;
		initial();
		templ.p1.x=p[1].x;
		if(check()) continue;
		templ.p1.y=p[1].y;
		if(check()) continue;
		puts("F");
	}
	return 0;
}
