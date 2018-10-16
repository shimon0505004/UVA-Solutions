#include<stdio.h>
#include<string.h>
#define Ubound 100005
int walks,n_v;
int answer[15];
char visit[15];
char map[15][15];
char is_answer;
void dfs(int now,int depth){
	int i;
	if(depth==walks+1){
		is_answer=1;
		putchar('(');
		printf("%d",answer[0]);
		for(i=1;i<=walks;i++) printf(",%d",answer[i]);
		puts(")");
		return;
	}
	for(i=1;i<=n_v;i++)
		if(visit[i]==0&&map[now][i]){
			visit[i]=1;
			answer[depth]=i;
			dfs(i,depth+1);
			visit[i]=0;
		}
}
int main(){
	int i,j,t,check;
	char start=0;
	do{
	scanf("%d%d",&n_v,&walks);
		if(start) puts("");
		else start=1;
		memset(map,0,sizeof(map));
		for(i=1;i<=n_v;i++){
			for(j=1;j<=n_v;j++){
				scanf("%d",&t);
				if(t) map[i][j]=1;
			}
			map[0][i]=1;
		}
		memset(visit,0,sizeof(visit));
		is_answer=0;
		visit[1]=1;
		answer[0]=1;
		dfs(1,1);
		if(is_answer==0) printf("no walk of length %d\n",walks);
	}while(scanf("%d",&check)==1&&check==-9999);
	return 0;
}
