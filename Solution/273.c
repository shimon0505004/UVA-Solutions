#include<stdio.h>
#include<string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
typedef struct POINT{
	int x;
	int y;
}Point;
typedef struct LINE{
	Point p1;
	Point p2;
}Line;
int Cross(Point p1,Point p2){
	return p1.x*p2.y-p2.x*p1.y;
}
int Dir(Point p1,Point p2,Point p3){
	Point tp1,tp2;
	tp1.x=p3.x-p1.x,tp1.y=p3.y-p1.y;
	tp2.x=p2.x-p1.x,tp2.y=p2.y-p1.y;
	return Cross(tp1,tp2);
}
int OnSeg(Point p1,Point p2,Point p3){
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
	if(d1==0&&OnSeg(L2.p1,L2.p2,L1.p1)) return 1;
	if(d2==0&&OnSeg(L2.p1,L2.p2,L1.p2)) return 1;
	if(d3==0&&OnSeg(L1.p1,L1.p2,L2.p1)) return 1;
	if(d4==0&&OnSeg(L1.p1,L1.p2,L2.p2)) return 1;
	return 0;
}
int main()
{
	int cases,n,i,j,k,q1,q2;
	char graph[15][15];
	Line line[15];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&line[i].p1.x,&line[i].p1.y,&line[i].p2.x,&line[i].p2.y);
		memset(graph,0,sizeof(graph));
		for(i=0;i<n;i++){
			graph[i][i]=1;
			for(j=0;j<i;j++)
				if(Intersect(line[i],line[j]))
					graph[i][j]=graph[j][i]=1;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(graph[i][j])
					for(k=0;k<n;k++)
						if(graph[j][k]) graph[i][k]=graph[k][i]=1;
		while(scanf("%d%d",&q1,&q2),q1+q2){
			if(graph[q1-1][q2-1]) puts("CONNECTED");
			else puts("NOT CONNECTED");
		}
		if(cases) puts("");
	}
	return 0;
}
