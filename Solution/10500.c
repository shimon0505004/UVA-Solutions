#include<stdio.h>
#include<string.h>
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void output(char robot[][12],int N,int M){
	int i,j;
	puts("");
	putchar('|');
	for(i=0;i<M;i++)
		printf("---|");
	puts("");
	for(i=1;i<=N;i++){
		putchar('|');
		for(j=1;j<=M;j++)
			printf(" %c |",robot[i][j]);
		puts("");
		putchar('|');
		for(j=1;j<=M;j++)
			printf("---|");
		puts("");
	}
	puts("");
}
int next(char map[][12],char robot[][12],int x,int y){
	int i,d=-1,n_x,n_y;
	for(i=0;i<4;i++){
		n_x=x+dir[i][0],n_y=y+dir[i][1];
		if(robot[n_x][n_y]=='V') continue;
		robot[n_x][n_y]=map[n_x][n_y];
		if(map[n_x][n_y]=='0'&&d==-1)
			d=i,robot[n_x][n_y]='V';
	}
	return d;
}
int main(){
	char map[12][12];
	char robot[12][12];
	int M,N,x,y,i,j,d,steps;
	while(scanf("%d%d",&N,&M),M+N){
		scanf("%d%d",&x,&y);
		memset(map,'X',sizeof(map));
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				scanf(" %c ",&map[i][j]);
		memset(robot,'?',sizeof(robot));
		robot[x][y]='V';
		for(steps=0;(d=next(map,robot,x,y))!=-1;steps++)
			x+=dir[d][0],y+=dir[d][1];
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				if(robot[i][j]=='V') robot[i][j]='0';
		output(robot,N,M);
		printf("NUMBER OF MOVEMENTS: %d\n",steps);
	}
	return 0;
}
