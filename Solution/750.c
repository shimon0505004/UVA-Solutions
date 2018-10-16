#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char chess[92][9],visit[9]={0},add[19]={0},subtract[17]={0};
char p[9],soln;
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
	int cases,i,j,x,y;
	soln=0;
	dfs(1);
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&x,&y);
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		soln=0;
		memset(p,0,sizeof(p));
		for(i=0;i<92;i++)
			if(chess[i][y]==x){
				printf("%2d     ",++soln);
				for(j=1;j<=8;j++)
					printf(" %d",chess[i][j]);
				puts("");
			}
		if(cases) puts("");
	}
	return 0;
}
