#include<stdio.h>
#include<string.h>
struct CELL{
	char visited;
	char east_wall,south_wall;
	int number;
};
int s_i,s_j,e_i,e_j;
void printMaze(struct CELL c[][15],int h,int w){
	int i,j;
	putchar('+');
	for(i=1;i<=w;i++) printf("---+");
	puts("");
	for(i=1;i<=h;i++){
		putchar('|');
		for(j=1;j<=w;j++){
			if(c[i][j].visited)
				if(c[i][j].number) printf("%3d",c[i][j].number);
				else printf("???");
			else printf("   ");
			if(c[i][j].east_wall) putchar('|');
			else putchar(' ');
		}
		puts("");
		putchar('+');
		for(j=1;j<=w;j++){
			if(c[i][j].south_wall) printf("---");
			else printf("   ");
			putchar('+');
		}
		puts("");
	}
}
int dfs(int now_i,int now_j,struct CELL cell[][15]){
	struct CELL *now=&cell[now_i][now_j],*next;
	now->visited=1;
	if(now_i==e_i&&now_j==e_j) return 1;
	next=&cell[now_i][now_j-1];
	if(next->east_wall==0&&next->visited==0){
		next->number=now->number+1;
		if(dfs(now_i,now_j-1,cell)) return 1;
		next->number=0;
	}
	next=&cell[now_i-1][now_j];
	if(next->south_wall==0&&next->visited==0){
		next->number=now->number+1;
		if(dfs(now_i-1,now_j,cell)) return 1;
		next->number=0;
	}
	next=&cell[now_i][now_j+1];
	if(now->east_wall==0&&next->visited==0){
		next->number=now->number+1;
		if(dfs(now_i,now_j+1,cell)) return 1;
		next->number=0;
	}
	next=&cell[now_i+1][now_j];
	if(now->south_wall==0&&next->visited==0){
		next->number=now->number+1;
		if(dfs(now_i+1,now_j,cell)) return 1;
		next->number=0;
	}
	return 0;
}
int main(){
	int h,w,i,j,check,cases;
	struct CELL cell[15][15];
	for(cases=1;scanf("%d%d%d%d%d%d",&h,&w,&s_i,&s_j,&e_i,&e_j),h|w|s_i|s_j|e_i|e_j;cases++){
		memset(cell,0,sizeof(cell));
		for(i=1;i<=w;i++) cell[0][i].south_wall=cell[h][i].south_wall=1;
		for(i=1;i<=h;i++) cell[i][0].east_wall=cell[i][w].east_wall=1;
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++){
				scanf("%d",&check);
				if(check&1) cell[i][j].east_wall=1;
				if(check&2) cell[i][j].south_wall=1;
			}
		cell[s_i][s_j].number=1;
		dfs(s_i,s_j,cell);
		printf("Maze %d\n\n",cases);
		printMaze(cell,h,w);
		puts("\n");
	}
	return 0;
}
