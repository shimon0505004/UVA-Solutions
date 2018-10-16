#include<stdio.h>
#include<string.h>
#define MAX 100
char pattern[3][4];
char panel[7][7];
int count[7][7];
int maximum[7][7];
int n_used;
char ans[30];
int r,c;
void switch_light(int x,int y){
	int i,j;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			if(pattern[1+i][1+j]=='*')
				panel[x+i][y+j]=1-panel[x+i][y+j];
}
void dfs(int depth,char used[]){
	int x=(depth-1)/c+1,y=(depth-1)%c+1;
	int i,j;
	for(i=1;i<=r;i++) for(j=1;j<=c;j++) if(count[i][j]==maximum[i][j]&&panel[i][j]==0) return;
	if(depth==r*c+1){
		int t_used=0;
		for(i=1;i<=r*c;i++) if(used[i]) t_used++;
		if(t_used<n_used) n_used=t_used,memcpy(ans,used,sizeof(ans));
		return;
	}
	for(i=-1;i<=1;i++) for(j=-1;j<=1;j++) count[x+i][y+j]++;
	switch_light(x,y);
	used[depth]=1;
	dfs(depth+1,used);
	used[depth]=0;
	switch_light(x,y);
	dfs(depth+1,used);
	for(i=-1;i<=1;i++) for(j=-1;j<=1;j++) count[x+i][y+j]--;
}
int main(){
	int cases,i,j,k,l;
	char used[30];
	for(cases=1;scanf("%d%d",&r,&c),r|c;cases++){
		for(i=0;i<3;i++) scanf("%s",pattern[i]);
		memset(panel,0,sizeof(panel));
		memset(count,0,sizeof(count));
		memset(maximum,0,sizeof(maximum));
		memset(used,0,sizeof(used));
		n_used=MAX;
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				for(k=-1;k<=1;k++)
					for(l=-1;l<=1;l++)
						maximum[i+k][j+l]++;
		printf("Case #%d\n",cases);
		dfs(1,used);
		if(n_used!=MAX){
			char start=0;
			for(i=1;i<=r*c;i++)
				if(ans[i]){
					if(start) printf(" ");
					else start=1;
					printf("%d",i);
				}
			puts("");
		}else puts("Impossible.");
	}
	return 0;
}
