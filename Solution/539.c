#include<stdio.h>
#include<string.h>
int n,m,longest,dis;
void dfs(char map[][30],int now){
	int i;
	for(i=0;i<n;i++)
		if(map[now][i]){
			map[now][i]=map[i][now]=0;
			if(++dis>longest) longest=dis;
			dfs(map,i);
			--dis;
			map[now][i]=map[i][now]=1;
		}
}
int main(){
	int a,b,i,dis;
	char map[30][30];
	while(scanf("%d%d",&n,&m),n|m){
		memset(map,0,sizeof(map));
		while(m--){
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;
		}
		longest=0;
		for(i=0;i<n;i++)
			dis=0,dfs(map,i);
		printf("%d\n",longest);
	}
	return 0;
}
