#include<stdio.h>
#include<string.h>
int table[105][105],n,k;
int hippity[105][105];
int top_down(int x,int y){
	int i,max=0;
	if(table[x][y]) return table[x][y];
	for(i=1;i<=k&&x+i<n;i++){
		int nx=x+i,ny=y;
		if(hippity[nx][ny]>hippity[x][y]&&top_down(nx,ny)>max)
			max=top_down(nx,ny);
	}
	for(i=1;i<=k&&x-i>=0;i++){
		int nx=x-i,ny=y;
		if(hippity[nx][ny]>hippity[x][y]&&top_down(nx,ny)>max)
			max=top_down(nx,ny);
	}
	for(i=1;i<=k&&y+i<n;i++){
		int nx=x,ny=y+i;
		if(hippity[nx][ny]>hippity[x][y]&&top_down(nx,ny)>max)
			max=top_down(nx,ny);
	}
	for(i=1;i<=k&&y-i>=0;i++){
		int nx=x,ny=y-i;
		if(hippity[nx][ny]>hippity[x][y]&&top_down(nx,ny)>max)
			max=top_down(nx,ny);
	}
	return table[x][y]=hippity[x][y]+max;
}
int main(){
	int cases,i,j;
	scanf("%d",&cases);
	while(cases--){
		memset(table,0,sizeof(table));
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&hippity[i][j]);
		printf("%d\n",top_down(0,0));
		if(cases) puts("");
	}
	return 0;
}
