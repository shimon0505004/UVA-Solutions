#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SIZE (55)
#define N 0
#define E 1
#define S 2
#define W 3
struct ROBOT{
	char dir;
	int x,y;
};
struct ROBOT queue[SIZE*SIZE];
int head,tail;
void initial(){
	head=tail=0;
}
int encode(struct ROBOT *rbt){
	return rbt->dir*SIZE*SIZE+rbt->x*SIZE+rbt->y;
}
void enqueue(struct ROBOT *rbt){
	queue[head++]=*rbt;
	head%=SIZE*SIZE;
}
struct ROBOT dequeue(){
	struct ROBOT res=queue[tail++];
	tail%=SIZE*SIZE;
	return res;
}
char is_empty(){
	return head==tail;
}
int main(){
	int m,n,Ex,Ey,Bx,By;
	char map[55][55];
	char visit[SIZE*SIZE*4],dir;
	int depth[SIZE*SIZE*4],i,j;
	struct ROBOT robot;
	while(scanf("%d%d",&m,&n),m|n){
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%hhd",&map[i][j]);
		scanf("%d%d%d%d %c%*s",&Bx,&By,&Ex,&Ey,&dir);
		robot.x=Bx,robot.y=By;
		switch(dir){
			case 'n': robot.dir=N;break;
			case 'e': robot.dir=E;break;
			case 'w': robot.dir=W;break;
			case 's': robot.dir=S;break;
		}

		if(robot.x<=0||robot.x>=m){
			puts("-1");
			continue;
		}
		if(robot.y<=0||robot.y>=n){
			puts("-1");
			continue;
		}
		if(map[robot.x][robot.y]||map[robot.x-1][robot.y]||map[robot.x][robot.y-1]||map[robot.x-1][robot.y-1]){
			puts("-1");
			continue;
		}
		memset(visit,0,sizeof(visit));
		memset(depth,0,sizeof(depth));
		visit[encode(&robot)]=1;
		initial();
		enqueue(&robot);
		while(!is_empty()){
			struct ROBOT next;
			int code,nxtcode;
			robot=dequeue();
			code=encode(&robot);
			if(robot.x==Ex&&robot.y==Ey) break;
			next=robot;
			next.dir=(next.dir+1)%4;
			nxtcode=encode(&next);
			if(visit[nxtcode]==0){
				visit[nxtcode]=1;
				depth[nxtcode]=depth[code]+1;
				enqueue(&next);
			}
			next=robot;
			next.dir=(next.dir+3)%4;
			nxtcode=encode(&next);
			if(visit[nxtcode]==0){
				visit[nxtcode]=1;
				depth[nxtcode]=depth[code]+1;
				enqueue(&next);
			}
			for(i=1;i<=3;i++){
				next=robot;
				switch(robot.dir){
					case N:
						next.x-=i;
						break;
					case E:
						next.y+=i;
						break;
					case W:
						next.y-=i;
						break;
					case S:
						next.x+=i;
						break;
				}
				if(next.x<=0||next.x>=m) break;
				if(next.y<=0||next.y>=n) break;
				if(map[next.x][next.y]||map[next.x-1][next.y]||map[next.x][next.y-1]||map[next.x-1][next.y-1]) break;
				nxtcode=encode(&next);
				if(visit[nxtcode]==0){
					visit[nxtcode]=1;
					depth[nxtcode]=depth[code]+1;
					enqueue(&next);
				}
			}
		}
		if(robot.x==Ex&&robot.y==Ey) printf("%d\n",depth[encode(&robot)]);
		else puts("-1");
	}
	return 0;
}
