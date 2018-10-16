#include<stdio.h>
#include<string.h>
void dfs(char visit[],char map[][128],int now){
	int i;
	visit[now]=0;
	for(i=0;i<128;i++)
		if(visit[i]&&map[now][i]){
			map[now][i]=map[i][now]=0;
			dfs(visit,map,i);
		}
}
int main(){
	int N,E,r,i,n_nonIsolate;
	char input[10],map[128][128],visit[128],from,to;
	while(scanf("%d%d",&N,&E)==2){
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		n_nonIsolate=0;
		for(i=0;i<E;i++){
			scanf(" %c %c",&from,&to);
			map[from][to]=map[to][from]=1;
			if(visit[from]==0)
				visit[from]=1,n_nonIsolate++;
			if(visit[to]==0)
				visit[to]=1,n_nonIsolate++;
		}
		r=0;
		for(i=0;i<128;i++)
			if(visit[i]) dfs(visit,map,i),r++;
		printf("%d\n",1+r+E-n_nonIsolate);
	}
	return 0;
}
