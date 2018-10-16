#include<stdio.h>
#include<string.h>
int main(){
	int N,n,m,i,j,cases,u,v,edges,other;
	int graph[105][105],neighs[105],answers[105];
	scanf("%d",&N);
	for(cases=1;cases<=N;cases++){
		memset(graph,0,sizeof(graph));
		memset(neighs,0,sizeof(neighs));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			graph[u][v]=graph[v][u]=1;
			neighs[u]++,neighs[v]++;
		}
		printf("Case #%d: ",cases);
		edges=0,other=1,answers[0]=1;
		for(i=2;i<=n;i++)
			if(graph[1][i]) neighs[i]-=2;
		for(i=2;i<=n;i++){
			if(neighs[i]>0){
				for(j=1;j<=n;j++)
					if(graph[i][j]) neighs[j]-=2;
				edges+=neighs[i];
				answers[other++]=i;
			}
		}
		printf("%d\n",other);
		printf("%d",answers[0]);
		for(i=1;i<other;i++)
			printf(" %d",answers[i]);
		puts("");
	}
	return 0;
}
