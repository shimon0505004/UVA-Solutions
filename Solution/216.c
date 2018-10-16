#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct POINT{
	int x,y;
}Point;
Point p[10];
int ans[10],temp[10];
char visit[10];
double min,distance[10][10];
int n;
double dis(Point p1,Point p2){
	int x=p1.x-p2.x,y=p1.y-p2.y;
	return sqrt(x*x+y*y);
}
void dfs(int now,int depth,double d){
	int i;
	if(depth==n){
		memmove(ans,temp,sizeof(temp));
		min=d;
		return;
	}
	for(i=0;i<n;i++){
		if(visit[i]) continue;
		if(d+distance[now][i]>min) continue;
		visit[i]=1;
		temp[depth]=i;
		dfs(i,depth+1,d+distance[now][i]);
		visit[i]=0;
	}
}
int main()
{
	int i,j,cases=0;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		min=1600;
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				distance[i][j]=distance[j][i]=dis(p[i],p[j])+16;
		memset(visit,0,sizeof(visit));
		for(i=0;i<n;i++){
			temp[0]=i;
			visit[i]=1;
			dfs(i,1,0);
			visit[i]=0;
		}
		puts("**********************************************************");
		printf("Network #%d\n",++cases);
		for(i=0;i<n-1;i++)
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[ans[i]].x,p[ans[i]].y,p[ans[i+1]].x,p[ans[i+1]].y,distance[ans[i]][ans[i+1]]);
		printf("Number of feet of cable required is %.2lf.\n",min);
	}
	return 0;
}
