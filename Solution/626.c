#include<stdio.h>
#include<string.h>
char eco[105][105],visit[105];
int cyc[4];
int cycs,n;
void dfs(int now,int depth){
	int i;
	cyc[depth]=now;
	if(depth==3){
		if((cyc[2]>cyc[1]&&cyc[2]>cyc[3])||(cyc[2]<cyc[1]&&cyc[2]<cyc[3])) return;
		if(eco[cyc[3]][cyc[1]]){
			printf("%d %d %d\n",cyc[1]+1,cyc[2]+1,cyc[3]+1);
			cycs++;
		}
		return;
	}
	for(i=0;i<n;i++){
		if(visit[i]) continue;
		if(now==-1||eco[now][i]){
			visit[i]=1;
			dfs(i,depth+1);
			visit[i]=0;
		}
	}
}
int main(){
	int i,j,temp;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&temp),eco[i][j]=temp;
		cycs=0;
		memset(visit,0,sizeof(visit));
		dfs(-1,0);
		printf("total:%d\n\n",cycs);
	}
	return 0;
}
