#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum DIRECTION{N,W,S,E}Dir;
char **maze;
int **count;
int x,y,h,w;
char WALL_ON_THE_RIGHT(){
	switch(Dir){
		case N: return maze[x][y+1]=='1';
		case W: return maze[x-1][y]=='1';
		case S: return maze[x][y-1]=='1';
		case E: return maze[x+1][y]=='1';
	}
}
void TURN_LEFT(){
	Dir++,Dir%=4;
}
void TURN_RIGHT(){
	Dir+=3,Dir%=4;
}
void GO(){
	switch(Dir){
		case N: 
			if(maze[x-1][y]=='1') TURN_LEFT();
			else count[x--][y]++;
			break;
		case W:
			if(maze[x][y-1]=='1') TURN_LEFT();
			else count[x][y--]++;
			break;
		case S:
			if(maze[x+1][y]=='1') TURN_LEFT();
			else count[x++][y]++;
			break;
		case E:
			if(maze[x][y+1]=='1') TURN_LEFT();
			else count[x][y++]++;
			break;
	}
	if(!WALL_ON_THE_RIGHT()) TURN_RIGHT();
	if(x!=h||y!=1) GO();
}
int main(){
	int i,j;
	int visit[5];
	while(scanf("%d%d",&h,&w),h|w){
		maze=(char **)malloc(sizeof(char *[h+2]));
		count=(int **)malloc(sizeof(int *[h+2]));
		memset(visit,0,sizeof(visit));
		for(i=0;i<h+2;i++) maze[i]=(char *)malloc(sizeof(char[w+2]));
		for(i=0;i<h+2;i++) count[i]=(int *)malloc(sizeof(int[w+2]));
		for(i=0;i<h+2;i++) for(j=0;j<w+2;j++) maze[i][j]='1',count[i][j]=0;
		for(i=1;i<=h;i++) scanf("%s",maze[i]+1),maze[i][w+1]='1';
		x=h,y=1,Dir=E;
		if(maze[h][1]=='1') Dir=N;
		GO();
		for(i=1;i<=h;i++) for(j=1;j<=w;j++) if(maze[i][j]=='0') visit[count[i][j]]++;
		printf("%3d",visit[0]);
		for(i=1;i<5;i++) printf("%3d",visit[i]);
		puts("");
		for(i=0;i<h+2;i++) free(maze[i]),free(count[i]);
		free(maze),free(count);
	}
	return 0;
}
