#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX 105
#define LENGTH 800
char graph[MAX][MAX],visit[MAX];
int DFN[MAX],pred[MAX],L[MAX],N,depth;
void dfs(int now){
	int i;
	visit[now]=1;
	DFN[now]=L[now]=depth++;
	for(i=1;i<=N;i++){
		if(graph[now][i]==0) continue;
		if(visit[i]==0){
			pred[i]=now;
			dfs(i);
			L[now]=MIN(L[i],L[now]);
		}else if(i!=pred[now])
			L[now]=MIN(L[now],DFN[i]);
	}
}
int main(){
	int from,to,len,articulation,i,j,adj_of_root;
	char input[LENGTH],*ptr;
	while(scanf("%d",&N),N){
		memset(graph,0,sizeof(graph));
		memset(visit,0,sizeof(visit));
		memset(pred,0,sizeof(pred));
		memset(L,0,sizeof(L));
		while(scanf("%d",&from),from){
			fgets(input,LENGTH,stdin);
			for(ptr=input;sscanf(ptr,"%d%n",&to,&len)==1;ptr+=len)
				graph[from][to]=graph[to][from]=1;
		}
		depth=0;
		dfs(1);
		adj_of_root=0;
		articulation=0;
		for(i=2;i<=N;i++) if(pred[i]==1) adj_of_root++;
		if(adj_of_root>1) articulation++;
		for(i=2;i<=N;i++)
			for(j=2;j<=N;j++)
				if(graph[i][j]&&pred[j]==i&&L[j]>=DFN[i]){
					articulation++;
					break;
				}
		printf("%d\n",articulation);
	}
	return 0;
}
