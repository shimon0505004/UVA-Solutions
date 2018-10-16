#include<stdio.h>
#include<string.h>
int secs;
char dfs(int start,char graph[][205],char visit[],int rest){
	int i;
	visit[start]=1,rest--;
	if(rest==0) return 1;
	for(i=0;i<secs;i++){
		if(visit[i]) continue;
		if(graph[start][i])
			if(dfs(i,graph,visit,rest)) return 1;
	}
	return 0;
}
int main(){
	char graph[205][205],visit[205];
	int degree[205],from,to,i,roads;
	while(scanf("%d%d",&secs,&roads)==2){
		memset(degree,0,sizeof(degree));
		memset(graph,0,sizeof(graph));
		memset(visit,0,sizeof(graph));
		while(roads--){
			scanf("%d%d",&from,&to);
			graph[from][to]=graph[to][from]=1;
			degree[from]++,degree[to]++;
		}
		for(i=0;i<secs;i++)
			if(degree[i]%2!=0||degree[i]==0) break;
		if(i<secs){
			puts("Not Possible");
			continue;
		}
		if(dfs(0,graph,visit,secs)) puts("Possible");
		else puts("Not Possible");
	}
	return 0;
}
