#include<stdio.h>
#include<string.h>
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void fill(char maze[][85],int x,int y){
	int i;
	maze[x][y]='#';
	for(i=0;i<8;i++)
		if(maze[x+dir[i][0]][y+dir[i][1]]==' ')
			fill(maze,x+dir[i][0],y+dir[i][1]);
}
int main(){
	char maze[35][85],*ptr;
	int cases,lines,i,j,x,y;
	scanf("%d ",&cases);
	while(cases--){
		for(lines=0;fgets(maze[lines],85,stdin)!=NULL;lines++){
			if((ptr=strchr(maze[lines],'*'))!=NULL) x=lines,y=ptr-maze[lines];
			else if(maze[lines][0]=='_') break;
		}
		fill(maze,x,y);
		for(i=0;i<lines;i++)
			printf(maze[i]);
		printf(maze[lines]);
	}
	return 0;
}
