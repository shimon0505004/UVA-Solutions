#include<stdio.h>
#include<string.h>
struct POINT{
	char H,V;
};
char isSquare(int x,int y,struct POINT p[][15],int size){
	int i;
	for(i=x;i<x+size;i++)
		if(!p[i][y].V||!p[i][y+size].V) return 0;
	for(i=y;i<y+size;i++)
		if(!p[x][i].H||!p[x+size][i].H) return 0;
	return 1;
}
int main(){
	int side,seg,x,y,i,j,squares,cases=0,size;
	char HorV,flag,start=0;
	struct POINT p[15][15];
	while(scanf("%d",&side)==1){
		if(start) puts("\n**********************************\n");
		start=1;
		memset(p,0,sizeof(p));
		scanf("%d ",&seg);
		for(i=0;i<seg;i++){
			scanf("%c%d%d ",&HorV,&x,&y);
			if(HorV=='H') p[x][y].H=1;
			else p[y][x].V=1;
		}
		flag=0;
		printf("Problem #%d\n\n",++cases);
		for(size=1;size<=side;size++){
			squares=0;
			for(i=1;i<=side-size;i++)
				for(j=1;j<=side-size;j++)
					if(isSquare(i,j,p,size)) squares++;
			if(squares){
				flag=1;
				printf("%d square (s) of size %d\n",squares,size);
			}
		}
		if(flag==0)
			puts("No completed squares can be found.");
	}
	return 0;
}
