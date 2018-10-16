#include<stdio.h>
const char *IEHOVA="IEHOVA#";
const char *direction[3]={"forth","right","left"};
int dir[3][2]={{0,-1},{1,0},{-1,0}};
void go(char map[][10],int x,int y,int depth){
	int i;
	for(i=0;i<3;i++){
		if(map[y+dir[i][1]][x+dir[i][0]]==IEHOVA[depth]){
			if(depth) putchar(' ');
			printf("%s",direction[i]);
			if(depth==6) break;
			go(map,x+dir[i][0],y+dir[i][1],depth+1);
			break;
		}
	}
}
int main()
{
	char map[10][10],*a,result[50];
	int cases,w,h,i,startx,starty;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&h,&w);
		memset(map,0,sizeof(map));
		for(i=1;i<=h;i++){
			scanf("%s",map[i]+1);
			if((a=strchr(map[i]+1,'@'))!=NULL) starty=i,startx=a-map[i];
		}
		go(map,startx,starty,0);
		puts("");
	}
	return 0;
}
