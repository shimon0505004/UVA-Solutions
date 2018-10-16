#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX 105
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
int search(char name[],char cityname[][35]){
	int i;
	for(i=1;;i++) if(strcmp(name,cityname[i])==0) return i;
}
int compar(const void *a,const void *b){
	return strcmp(*((char **)a),*((char **)b));
}
int main(){
	int articulation,i,j,adj_of_root,M;
	char cityname[MAX][35];
	int cases,frontier;
	char *arti[MAX];
	for(cases=1;scanf("%d",&N),N;cases++){
		if(cases>1) puts("");
		memset(graph,0,sizeof(graph));
		memset(visit,0,sizeof(visit));
		memset(pred,0,sizeof(pred));
		memset(L,0,sizeof(L));
		for(i=1;i<=N;i++) scanf("%s",cityname[i]);
		scanf("%d",&M);
		while(M--){
			char name1[35],name2[35];
			int from,to;
			scanf("%s%s",name1,name2);
			from=search(name1,cityname);
			to=search(name2,cityname);
			graph[from][to]=graph[to][from]=1;
		}
		articulation=0;
		for(frontier=1;frontier<=N;frontier++){
			if(visit[frontier]) continue;
			depth=0;
			dfs(frontier);
			adj_of_root=0;
			for(i=1;i<=N;i++) if(pred[i]==frontier) adj_of_root++;
			if(adj_of_root>1) arti[articulation++]=cityname[frontier];
		}
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				if(graph[i][j]&&pred[j]==i&&L[j]>=DFN[i]&&DFN[i]!=0){
					arti[articulation++]=cityname[i];
					break;
				}
		printf("City map #%d: %d camera(s) found\n",cases,articulation);
		qsort(arti,articulation,sizeof(char *),compar);
		for(i=0;i<articulation;i++) puts(arti[i]);
	}
	return 0;
}
