#include<stdio.h>
#include<string.h>
char graph[25][25],visit[25];
char reach[25][25];
int out[25],dest,max,routes;
void dfs(int pos,int depth){
	int i;
	if(pos==dest){
		putchar('1');
		for(i=0;i<depth;i++)
			printf(" %d",out[i]);
		puts("");
		routes++;
		return;
	}
	for(i=2;i<=max;i++)
		if(graph[pos][i]&&!visit[i]&&reach[i][dest]){
			graph[pos][i]=graph[i][pos]=0;
			out[depth]=i;
			visit[i]=1;
			dfs(i,depth+1);
			visit[i]=0;
			graph[pos][i]=graph[i][pos]=1;
		}
}
int main()
{
	int c1,c2,cases=0,i,j,k;
	while(scanf("%d",&dest)==1){
		max=routes=0;
		memset(graph,0,sizeof(graph));
		memset(visit,0,sizeof(visit));
		while(scanf("%d%d",&c1,&c2),c1){
			graph[c1][c2]=graph[c2][c1]=1;
			if(c1>max) max=c1;
			if(c2>max) max=c2;
		}
		memmove(reach,graph,sizeof(reach));
		for(i=1;i<=max;i++)
			for(j=1;j<=max;j++)
				if(reach[i][j]==0)
					for(k=1;k<=max;k++)
						if(reach[i][k]&&reach[k][j]){
							reach[i][j]=reach[j][i]=1;
							break;
						}
		printf("CASE %d:\n",++cases);
		dfs(1,0);
		printf("There are %d routes from the firestation to streetcorner %d.\n",routes,dest);
	}
	return 0;
}
