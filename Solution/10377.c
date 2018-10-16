#include<stdio.h>
typedef struct robot{
	int x;
	int y;
	int face;
}Robot;
int main()
{
	Robot RBT;
	int cases,w,h;
	char maze[65][65],act;
	int sx,sy;
	int i;
	int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
	char *dirname="NESW";
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d ",&h,&w);
		for(i=1;i<=h;i++)
			fgets(maze[i]+1,100,stdin);
		scanf("%d%d ",&sy,&sx);
		RBT.x=sx;
		RBT.y=sy;
		RBT.face=0;
		for(act=getchar();act!='Q';act=getchar()){
			switch(act){
				case 'R':
					RBT.face=(RBT.face+1)%4;
					break;
				case 'L':
					RBT.face=(RBT.face+3)%4;
					break;
				case 'F':
					if(maze[RBT.y+dir[RBT.face][0]][RBT.x+dir[RBT.face][1]]!='*'){
						RBT.y+=dir[RBT.face][0];
						RBT.x+=dir[RBT.face][1];
					}
					break;
			}
		}
		printf("%d %d %c\n",RBT.y,RBT.x,dirname[RBT.face]);
		if(cases) printf("\n");
	}
	return 0;
}
