#include<stdio.h>
#include<math.h>
#include<string.h>
#define sqr(x) ((x)*(x))
struct student{
	int x,y;
}s[20];
int N;
char visit[20];
double min,dis[20][20];
double distance(struct student s1,struct student s2){
	return sqrt(sqr(s1.x-s2.x)+sqr(s1.y-s2.y));
}
void dfs(int start,int depth,double now){
	int i,j;
	if(depth==N){
		min=now;
		return;
	}
	for(i=start+1;i<2*N;i++){
		if(visit[i]) continue;
		for(j=i+1;j<2*N;j++){
			if(visit[j]) continue;
			if(now+dis[i][j]>min) continue;
			visit[i]=visit[j]=1;
			dfs(i,depth+1,now+dis[i][j]);
			visit[i]=visit[j]=0;
		}
	}
}
int main(){
	int i,j,cases;
	char name[25];
	for(cases=1;scanf("%d",&N),N;cases++){
		for(i=0;i<2*N;i++)
			scanf("%s%d%d",name,&s[i].x,&s[i].y);
		min=1e8;
		for(i=0;i<2*N;i++)
			for(j=0;j<i;j++)
				dis[i][j]=dis[j][i]=distance(s[i],s[j]);
		memset(visit,0,sizeof(visit));
		dfs(-1,0,0.0);
		printf("Case %d: %.2lf\n",cases,min);
	}
	return 0;
}
