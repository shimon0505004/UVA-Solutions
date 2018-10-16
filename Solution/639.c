#include<stdio.h>
struct MAP{
	char map[4][5];
};
int n,rooks,max;
void dfs(int depth,int x,int y,struct MAP m){
	int i,j;
	m.map[y][x]='O';
	for(i=x+1;i<n;i++){
		if(m.map[y][i]!='.') break;
		m.map[y][i]='F';
	}
	for(i=x-1;i>=0;i--){
		if(m.map[y][i]!='.') break;
		m.map[y][i]='F';
	}
	for(i=y+1;i<n;i++){
		if(m.map[i][x]!='.') break;
		m.map[i][x]='F';
	}
	for(i=y-1;i>=0;i--){
		if(m.map[i][x]!='.') break;
		m.map[i][x]='F';
	}
	for(i=y;i<n;i++)
		for(j=0;j<n;j++)
			if(m.map[i][j]=='.')
				dfs(depth+1,j,i,m);
	if(depth>max) max=depth;
}
int main(){
	int i,j;
	struct MAP m;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)
			scanf("%s",m.map[i]);
		max=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(m.map[i][j]=='.')
					dfs(1,j,i,m);
		printf("%d\n",max);
	}
	return 0;
}
