#include<stdio.h>
#include<string.h>
#define c(a,b) ((a)*100+(b))
char map[100][100];
int root[10100];
int N;
int find_root(int n){
	if(root[n]!=n) root[n]=find_root(root[n]);
	return root[n];
}
void link(int dest,int src){
	root[src]=dest;
}
char w_win_path(){
	if(find_root(c(1,0))==find_root(c(1,N+1))) return 1;
	return 0;
}
char b_win_path(){
	if(find_root(c(0,1))==find_root(c(N+1,1))) return 1;
	return 0;
}
char w_win_one(){
	int i,j;
	int w_l=find_root(c(1,0)),w_r=find_root(c(1,N+1));
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(map[i][j]=='U'){
				if(find_root(c(i-1,j))!=w_l&&find_root(c(i+1,j))!=w_l&&find_root(c(i,j-1))!=w_l&&find_root(c(i,j+1))!=w_l) continue;
				if(find_root(c(i-1,j))!=w_r&&find_root(c(i+1,j))!=w_r&&find_root(c(i,j-1))!=w_r&&find_root(c(i,j+1))!=w_r) continue;
				return 1;
			}
	return 0;
}
char b_win_one(){
	int i,j;
	int b_t=find_root(c(0,1)),b_d=find_root(c(N+1,1));
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(map[i][j]=='U'){
				if(find_root(c(i-1,j))!=b_t&&find_root(c(i+1,j))!=b_t&&find_root(c(i,j-1))!=b_t&&find_root(c(i,j+1))!=b_t) continue;
				if(find_root(c(i-1,j))!=b_d&&find_root(c(i+1,j))!=b_d&&find_root(c(i,j-1))!=b_d&&find_root(c(i,j+1))!=b_d) continue;
				return 1;
			}
	return 0;
}
int main(){
	int i,j;
	while(scanf("%d",&N),N){
		memset(map,0,sizeof(map));
		memset(root,0,sizeof(root));
		for(i=1;i<=N;i++)
			scanf("%s",map[i]+1);
		for(i=1;i<=N;i++) map[i][0]=map[i][N+1]='W',root[c(i,0)]=c(1,0),root[c(i,N+1)]=c(1,N+1);
		for(i=1;i<=N;i++) map[0][i]=map[N+1][i]='B',root[c(0,i)]=c(0,1),root[c(N+1,i)]=c(N+1,1);
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				root[c(i,j)]=c(i,j);
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				if(map[i][j]=='W'||map[i][j]=='B'){
					if(map[i][j-1]==map[i][j]) link(find_root(c(i,j-1)),find_root(c(i,j)));
					if(map[i][j+1]==map[i][j]) link(find_root(c(i,j+1)),find_root(c(i,j)));
					if(map[i+1][j]==map[i][j]) link(find_root(c(i+1,j)),find_root(c(i,j)));
					if(map[i-1][j]==map[i][j]) link(find_root(c(i-1,j)),find_root(c(i,j)));
				}
		if(w_win_path()) puts("White has a winning path.");
		else if(b_win_path()) puts("Black has a winning path.");
		else if(w_win_one()) puts("White can win in one move.");
		else if(b_win_one()) puts("Black can win in one move.");
		else puts("There is no winning path.");
	}
	return 0;
}
