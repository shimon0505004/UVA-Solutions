#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char chess[92][9],visit[9]={0},add[19]={0},subtract[17]={0};
char p[9],soln;
int max;
void dfs(int depth){
	int i;
	if(depth==9){
		for(i=1;i<=8;i++)
			chess[soln][i]=p[i];
		soln++;
	}else{
		for(i=1;i<=8;i++){
			if(visit[i]) continue;
			if(!visit[i]&&!add[depth+i]&&!subtract[depth-i+8]){
				p[depth]=i;
				visit[i]=1;
				add[depth+i]=1;
				subtract[depth-i+8]=1;
				dfs(depth+1);
				subtract[depth-i+8]=0;
				add[depth+i]=0;
				p[depth]=0;
				visit[i]=0;
			}
		}
	}
}
int main()
{
	int cases,i,j;
	int chessboard[9][9];
	dfs(1);
	scanf("%d",&cases);
	while(cases--){
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				scanf("%d",&chessboard[i][j]);
		max=0;
		for(i=0;i<92;i++){
			int tot=0;
			for(j=1;j<=8;j++)
				tot+=chessboard[j][chess[i][j]];
			if(tot>max) max=tot;
		}
		printf("%5d\n",max);
	}
	return 0;
}
