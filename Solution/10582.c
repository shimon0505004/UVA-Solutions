#include<stdio.h>
#include<string.h>
#define I -1
#define L 1
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
char map[65][65];
char visit[65][65];
int m,n;
int dfs(int x,int y,int from){
	int res=0;
	if(x==m-1&&y==n-1&&map[x][y]) return 1;
	if(visit[x][y]) return 0;
	visit[x][y]=1;
	if(map[x][y]==L){
		switch(from){
			case UP:
			case DOWN:
				if(y+1<n) res+=dfs(x,y+1,LEFT);
				if(y>0) res+=dfs(x,y-1,RIGHT);
				break;
			case LEFT:
			case RIGHT:
				if(x+1<m) res+=dfs(x+1,y,UP);
				if(x>0) res+=dfs(x-1,y,DOWN);
				break;
		}
	}else if(map[x][y]==I){
		switch(from){
			case UP:
				if(x+1<m) res+=dfs(x+1,y,UP);
				break;
			case DOWN:
				if(x>0) res+=dfs(x-1,y,DOWN);
				break;
			case LEFT:
				if(y+1<n) res+=dfs(x,y+1,LEFT);
				break;
			case RIGHT:
				if(y>0) res+=dfs(x,y-1,RIGHT);
				break;
		}
	}
	visit[x][y]=0;
	return res;
}
int main(){
	int cases;
	char line[325];
	int i,j;
	int result;
	scanf("%d",&cases);
	while(cases--){
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		scanf("%d%d ",&m,&n);
		fgets(line,325,stdin);
		for(i=0;i<m;i++){
			fgets(line,325,stdin);
			fgets(line,325,stdin);
			for(j=0;j<n;j++){
				if(line[4*j+2]=='*'){
					if((line[4*j+1]=='*')^(line[4*j+3]=='*')) map[i][j]=L;
					else map[i][j]=I;
				}
			}
			fgets(line,325,stdin);
			fgets(line,325,stdin);
		}
		result=dfs(0,0,UP)+dfs(0,0,LEFT);
		printf("Number of solutions: %d\n",result);
	}
	return 0;
}
