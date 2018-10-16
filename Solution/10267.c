#include<stdio.h>
#include<string.h>
int W,H;
void draw(char map[][280],int X1,int Y1,int X2,int Y2,char C){
	int i,j,t;
	if(X1>X2) t=X1,X1=X2,X2=t;
	if(Y1>Y2) t=Y1,Y1=Y2,Y2=t;
	if(X2>H) X2=H;
	if(Y2>W) Y2=W;
	for(i=X1;i<=X2;i++)
		for(j=Y1;j<=Y2;j++)
			map[i][j]=C;
}
void print(char map[][280]){
	int i;
	for(i=1;i<=H;i++)
		puts(map[i]+1);
}
void fill(char map[][280],int X,int Y,char D,char C){
	if(D==C) return;
	if(X>H||Y>W) return;
	map[X][Y]=D;
	if(map[X-1][Y-1]==C)
		fill(map,X-1,Y-1,D,C);
	if(map[X-1][Y]==C)
		fill(map,X-1,Y,D,C);
	if(map[X-1][Y+1]==C)
		fill(map,X-1,Y+1,D,C);
	if(map[X][Y-1]==C)
		fill(map,X,Y-1,D,C);
	if(map[X][Y+1]==C)
		fill(map,X,Y+1,D,C);
	if(map[X+1][Y-1]==C)
		fill(map,X+1,Y-1,D,C);
	if(map[X+1][Y]==C)
		fill(map,X+1,Y,D,C);
	if(map[X+1][Y+1]==C)
		fill(map,X+1,Y+1,D,C);
}
int main(){
	char command[200];
	char name[200];
	char map[280][280]={0};
	int M,N,X,Y,C,X1,X2,Y1,Y2;
	W=H=0;
	while(fgets(command,200,stdin)!=NULL){
		switch(*command){
			case 'I':
				sscanf(command+1,"%d%d",&M,&N);
				memset(map,0,sizeof(map));
				W=M,H=N;
				draw(map,1,1,H,W,'O');
				break;
			case 'C':
				draw(map,1,1,H,W,'O');
				break;
			case 'L':
				sscanf(command+1,"%d%d %c",&X,&Y,&C);
				draw(map,Y,X,Y,X,C);
				break;
			case 'V':
				sscanf(command+1,"%d%d%d %c",&X,&Y1,&Y2,&C);
				draw(map,Y1,X,Y2,X,C);
				break;
			case 'H':
				sscanf(command+1,"%d%d%d %c",&X1,&X2,&Y,&C);
				draw(map,Y,X1,Y,X2,C);
				break;
			case 'K':
				sscanf(command+1,"%d%d%d%d %c",&X1,&Y1,&X2,&Y2,&C);
				draw(map,Y1,X1,Y2,X2,C);
				break;
			case 'F':
				sscanf(command+1,"%d%d %c",&X,&Y,&C);
				fill(map,Y,X,C,map[Y][X]);
				break;
			case 'S':
				sscanf(command+2,"%[^\n]",name);
				puts(name);
				print(map);
				break;
			case 'X':
				return 0;
		}
	}
	return 0;
}
