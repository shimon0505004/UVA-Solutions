#include<stdio.h>
#include<string.h>
#define S 0
#define W 1
int main(){
	int cases;
	long long grid[40][40];
	char obstacle[40][40][2];
	int s_x,s_y,e_x,e_y,o_x,o_y;
	int n_obs,x,y,N;
	char dir;
	scanf("%d",&cases);
	while(cases--){
		memset(grid,0,sizeof(grid));
		memset(obstacle,0,sizeof(obstacle));
		scanf("%d",&N);
		scanf("%d%d%d%d",&s_x,&s_y,&e_x,&e_y);
		scanf("%d",&n_obs);
		while(n_obs--){
			scanf("%d%d %c",&o_x,&o_y,&dir);
			if(dir=='S') obstacle[o_x][o_y][S]=1;
			else if(dir=='W') obstacle[o_x][o_y][W]=1;
			else if(dir=='N') obstacle[o_x][o_y+1][S]=1;
			else if(dir=='E') obstacle[o_x+1][o_y][W]=1;
		}
		grid[s_x][s_y]=1;
		for(x=s_x;x<=e_x;x++)
			for(y=s_y;y<=e_y;y++){
				if(obstacle[x][y][S]==0) grid[x][y]+=grid[x][y-1];
				if(obstacle[x][y][W]==0) grid[x][y]+=grid[x-1][y];
			}
		printf("%lld\n",grid[e_x][e_y]);
	}
	return 0;
}
