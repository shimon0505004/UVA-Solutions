#include<stdio.h>
#include<string.h>
char visit[35][100];
void dfs(char contour[][100],int x,int y,char mark){
	visit[x][y]=1,contour[x][y]=mark;
	if(visit[x-1][y]==0&&contour[x-1][y]==' ') dfs(contour,x-1,y,mark);
	if(visit[x][y-1]==0&&contour[x][y-1]==' ') dfs(contour,x,y-1,mark);
	if(visit[x+1][y]==0&&contour[x+1][y]==' ') dfs(contour,x+1,y,mark);
	if(visit[x][y+1]==0&&contour[x][y+1]==' ') dfs(contour,x,y+1,mark);
}
int main(){
	char contour[35][100];
	int i,j,n_line;
	for(;;){
		memset(contour,0,sizeof(contour));
		memset(visit,0,sizeof(visit));
		if(fgets(contour[1]+1,100,stdin)==NULL) break;
		for(n_line=2;fgets(contour[n_line]+1,100,stdin),contour[n_line][1]!='_';n_line++);
		for(i=1;i<n_line;i++)
			for(j=1;contour[i][j]!='\n';j++){
				if(visit[i][j]||contour[i][j]=='X'||contour[i][j]==' ') continue;
				dfs(contour,i,j,contour[i][j]);
			}
		for(i=1;i<=n_line;i++) printf(contour[i]+1);
	}
	return 0;
}
