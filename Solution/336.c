#include<stdio.h>
#include<string.h>
int f[35],nodes;
int map(int n){
	int i;
	for(i=0;i<nodes;i++)
		if(f[i]==n) return i;
	f[nodes]=n;
	return nodes++;
}
int main(){
	int paths,i,j,k,t,cases=0;
	int n1,n2,m1,m2,start,TTL,unreachable;
	int graph[35][35];
	while(scanf("%d",&paths),paths){
		memset(graph,1,sizeof(graph));
		nodes=0;
		while(paths--){
			scanf("%d%d",&n1,&n2);
			m1=map(n1),m2=map(n2);
			if(m1==m2) continue;
			graph[m1][m2]=graph[m2][m1]=1;
		}
		for(k=0;k<nodes;k++)
			for(i=0;i<nodes;i++)
				for(j=0;j<i;j++){
					t=graph[i][k]+graph[k][j];
					if(t<graph[i][j])
						graph[i][j]=graph[j][i]=t;
				}
		while(scanf("%d%d",&start,&TTL),start+TTL){
			unreachable=0;
			for(i=0;i<nodes;i++)
				if(graph[map(start)][i]>TTL) unreachable++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cases,unreachable-1,start,TTL);
		}
	}
	return 0;
}
