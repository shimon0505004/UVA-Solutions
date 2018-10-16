#include<stdio.h>
#include<string.h>
char ans[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,-1,1,1},{0,0,0,0,1},{0,0,0,0,0}};
int min;
void dfs(char map[][5],int nowx,int nowy,int depth){
	int nextx,nexty;
	if(nowx==2&&nowy==2&&memcmp(ans,map,sizeof(char[5][5]))==0){
		min=depth;
		return;
	}
	if(depth+1>=min) return;
	if(nowx>1){
		if(nowy>0){
			nextx=nowx-2,nexty=nowy-1;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
		if(nowy<4){
			nextx=nowx-2,nexty=nowy+1;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
	}
	if(nowx>0){
		if(nowy>1){
			nextx=nowx-1,nexty=nowy-2;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
		if(nowy<3){
			nextx=nowx-1,nexty=nowy+2;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
	}
	if(nowx<4){
		if(nowy>1){
			nextx=nowx+1,nexty=nowy-2;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
		if(nowy<3){
			nextx=nowx+1,nexty=nowy+2;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
	}
	if(nowx<3){
		if(nowy>0){
			nextx=nowx+2,nexty=nowy-1;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
		if(nowy<4){
			nextx=nowx+2,nexty=nowy+1;
			map[nowx][nowy]=map[nextx][nexty];
			map[nextx][nexty]=-1;
			dfs(map,nextx,nexty,depth+1);
			map[nextx][nexty]=map[nowx][nowy];
		}
	}
}
int main(){
	char map[5][5];
	int cases,i,j;
	int sx,sy;
	scanf("%d%*c",&cases);
	while(cases--){
		for(i=0;i<5;i++,getchar())
			for(j=0;j<5;j++){
				char c=getchar();
				if(c=='0') map[i][j]=0;
				else if(c=='1') map[i][j]=1;
				else map[i][j]=-1,sx=i,sy=j;
			}
		min=11;
		dfs(map,sx,sy,0);
		if(min>10) puts("Unsolvable in less than 11 move(s).");
		else printf("Solvable in %d move(s).\n",min);
	}
	return 0;
}
