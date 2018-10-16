#include<stdio.h>
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3
struct BALL{
	int x,y,score,lifetime,direction;
};
struct GRID{
	int cost,value,x,y;
	char isobstacle;
};
void LuckyBall_GO(struct BALL *b,struct GRID map[][55]){
	struct GRID nextgrid;
	while(b->lifetime>1){
		if(b->direction==UP) nextgrid=map[b->y+1][b->x];
		else if(b->direction==LEFT) nextgrid=map[b->y][b->x-1];
		else if(b->direction==DOWN) nextgrid=map[b->y-1][b->x];
		else nextgrid=map[b->y][b->x+1];
		if(nextgrid.isobstacle){
			b->direction=(b->direction+3)%4;
			b->lifetime-=nextgrid.cost;
			b->score+=nextgrid.value;
		}else
			b->x=nextgrid.x,b->y=nextgrid.y;
		b->lifetime--;
	}
	return;
}
int main(){
	int m,n,wallcost,bumpers,x,y,totalscore;
	struct BALL b;
	struct GRID map[55][55];
	scanf("%d%d",&m,&n);
	scanf("%d",&wallcost);
	for(x=1;x<=m;x++){
		for(y=1;y<=n;y++){
			if(x==1||y==1||x==m||y==n){
				map[y][x].cost=wallcost;
				map[y][x].isobstacle=1;
			}else{
				map[y][x].cost=1;
				map[y][x].isobstacle=0;
			}
			map[y][x].value=0;
			map[y][x].value=0;
			map[y][x].y=y,map[y][x].x=x;
		}
	}
	scanf("%d",&bumpers);
	while(bumpers--){
		int v,c;
		scanf("%d%d",&x,&y);
		scanf("%d%d",&v,&c);
		map[y][x].value=v;
		map[y][x].cost=c;
		map[y][x].isobstacle=1;
	}
	totalscore=0;
	while(scanf("%d%d%d%d",&b.x,&b.y,&b.direction,&b.lifetime)==4){
		b.score=0;
		LuckyBall_GO(&b,map);
		printf("%d\n",b.score);
		totalscore+=b.score;
	}
	printf("%d\n",totalscore);
	return 0;
}
