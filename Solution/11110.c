#include<stdio.h>
#include<string.h>
char count(int map[][105],char visit[][105],int i,int j){
	int res=1;
	visit[i][j]=1;
	if(visit[i+1][j]==0&&map[i+1][j]==map[i][j]) res+=count(map,visit,i+1,j);
	if(visit[i][j+1]==0&&map[i][j+1]==map[i][j]) res+=count(map,visit,i,j+1);
	if(visit[i-1][j]==0&&map[i-1][j]==map[i][j]) res+=count(map,visit,i-1,j);
	if(visit[i][j-1]==0&&map[i][j-1]==map[i][j]) res+=count(map,visit,i,j-1);
	return res;
}
char Equidivision(int N,int map[][105]){
	char visit[105][105]={{0}};
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(!visit[i][j])
				if(count(map,visit,i,j)!=N) return 0;
	return 1;
}
int main(){
	int N,i,j,x,y;
	int map[105][105];
	char line[1000];
	while(scanf("%d ",&N),N){
		memset(map,0,sizeof(map));
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				map[i][j]=N;
		for(i=1;i<N;i++){
			char *ptr;
			int len;
			fgets(line,1000,stdin);
			for(ptr=line;sscanf(ptr,"%d%d%n",&x,&y,&len)==2;ptr+=len)
				map[x][y]=i;
		}
		if(Equidivision(N,map)) puts("good");
		else puts("wrong");
	}
	return 0;
}
