#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct POINT{
	int x,y;
}Point;
Point p[10];
int path[10];
char visit[10];
int min,distance[10][10];
int n;
int dis(Point p1,Point p2){
	int x=abs(p1.x-p2.x),y=abs(p1.y-p2.y);
	return x+y;
}
void dfs(int now,int depth,int d){
	int i;
	if(depth==n){
		min=d+distance[path[n-1]][0];
		return;
	}
	for(i=1;i<n;i++){
		if(visit[i]) continue;
		if(d+distance[now][i]+distance[i][0]>min) continue;
		visit[i]=1;
		path[depth]=i;
		dfs(i,depth+1,d+distance[now][i]);
		visit[i]=0;
	}
}
int main()
{
	int i,j,foo,bar,cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&foo,&bar);
		scanf("%d%d",&p[0].x,&p[0].y);
		scanf("%d",&n),n++;
		for(i=1;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		min=260;
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				distance[i][j]=distance[j][i]=dis(p[i],p[j]);
		memset(visit,0,sizeof(visit));
		dfs(0,1,0);
		printf("The shortest path has length %d\n",min);
	}
	return 0;
}
