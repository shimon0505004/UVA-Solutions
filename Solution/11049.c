#include<stdio.h>
#define N 1
#define E 2
#define W 4
#define S 8
struct POS{
	int x,y;
};
struct GRID{
	int shortest;
	char visit,isBlock,prev;
};
struct POS queue[40];
int head,tail;
struct POS dequeue(){
	int result=tail++;
	tail%=40;
	return queue[result];
}
void enqueue(struct POS *p){
	queue[head++]=*p;
	head%=40;
}
char is_empty(){
	return head==tail;
}
void printRoute(struct GRID g[][8],struct POS *now){
	if(g[now->y][now->x].prev==N){
		putchar('N');
		now->y--;
	}else if(g[now->y][now->x].prev==E){
		putchar('E');
		now->x++;
	}else if(g[now->y][now->x].prev==W){
		putchar('W');
		now->x--;
	}else if(g[now->y][now->x].prev==S){
		putchar('S');
		now->y++;
	}else return;
	printRoute(g,now);
}
int main(){
	struct POS start,end,wall_s,wall_e;
	struct GRID grid[8][8];
	int i,j,walls;
	while(scanf("%d%d",&start.x,&start.y),start.x||start.y){
		scanf("%d%d",&end.x,&end.y);
		for(i=1;i<=6;i++){
			for(j=1;j<=6;j++){
				grid[i][j].shortest=40;
				grid[i][j].visit=0;
				grid[i][j].isBlock=0;
				grid[i][j].prev=0;
				if(i==1) grid[i][j].isBlock|=N;
				else if(i==6) grid[i][j].isBlock|=S;
				if(j==1) grid[i][j].isBlock|=W;
				else if(j==6) grid[i][j].isBlock|=E;
			}
		}
		walls=3;
		while(walls--){
			scanf("%d%d%d%d",&wall_s.x,&wall_s.y,&wall_e.x,&wall_e.y);
			if(wall_s.y==wall_e.y){
				for(i=wall_s.x+1;i<=wall_e.x;i++){
					grid[wall_s.y][i].isBlock|=S;
					grid[wall_s.y+1][i].isBlock|=N;
				}
			}else if(wall_s.x==wall_e.x){
				for(i=wall_s.y+1;i<=wall_e.y;i++){
					grid[i][wall_s.x].isBlock|=E;
					grid[i][wall_s.x+1].isBlock|=W;
				}
			}
		}
		grid[end.y][end.x].visit=1;
		grid[end.y][end.x].shortest=0;
		enqueue(&end);
		while(!is_empty()){
			struct POS now=dequeue(),neigh;
			if(now.x==start.x&&now.y==start.y) break;
			if(!(grid[now.y][now.x].isBlock&N)){
				neigh=now,neigh.y--;
				if(grid[neigh.y][neigh.x].visit==0){
					grid[neigh.y][neigh.x].visit=1;
					grid[neigh.y][neigh.x].shortest=grid[now.y][now.x].shortest+1;
					grid[neigh.y][neigh.x].prev=S;
					enqueue(&neigh);
				}
			}
			if(!(grid[now.y][now.x].isBlock&E)){
				neigh=now,neigh.x++;
				if(grid[neigh.y][neigh.x].visit==0){
					grid[neigh.y][neigh.x].visit=1;
					grid[neigh.y][neigh.x].shortest=grid[now.y][now.x].shortest+1;
					grid[neigh.y][neigh.x].prev=W;
					enqueue(&neigh);
				}
			}
			if(!(grid[now.y][now.x].isBlock&W)){
				neigh=now,neigh.x--;
				if(grid[neigh.y][neigh.x].visit==0){
					grid[neigh.y][neigh.x].visit=1;
					grid[neigh.y][neigh.x].shortest=grid[now.y][now.x].shortest+1;
					grid[neigh.y][neigh.x].prev=E;
					enqueue(&neigh);
				}
			}
			if(!(grid[now.y][now.x].isBlock&S)){
				neigh=now,neigh.y++;
				if(grid[neigh.y][neigh.x].visit==0){
					grid[neigh.y][neigh.x].visit=1;
					grid[neigh.y][neigh.x].shortest=grid[now.y][now.x].shortest+1;
					grid[neigh.y][neigh.x].prev=N;
					enqueue(&neigh);
				}
			}
		}
		head=tail=0;
		printRoute(grid,&start);
		puts("");
	}
	return 0;
}
