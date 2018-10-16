#include<stdio.h>
#include<string.h>
#define SIZE 1005
#define SIZE_SQR 1000005
struct POINT{
	int x,y;
};
struct POINT queue[SIZE_SQR];
int head,tail;
void enqueue(struct POINT p){
	queue[head++]=p;
	head%=SIZE_SQR;
}
struct POINT dequeue(){
	struct POINT result=queue[tail++];
	tail%=SIZE_SQR;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int R,C,r,c,n;
	int rows;
	struct POINT src,dest;
	char map[SIZE][SIZE];
	int visit[SIZE][SIZE];
	while(scanf("%d%d",&R,&C),R|C){
		memset(map,0,sizeof(map));
		scanf("%d",&rows);
		while(rows--){
			scanf("%d%d",&r,&n);
			while(n--){
				scanf("%d",&c);
				map[r][c]=1;
			}
		}
		scanf("%d%d%d%d",&src.x,&src.y,&dest.x,&dest.y);
		memset(visit,0,sizeof(visit));
		head=tail=0;
		enqueue(src);
		visit[src.x][src.y]=1;
		while(!is_empty()){
			struct POINT now=dequeue();
			struct POINT next;
			if(now.x>0){
				next=now,next.x--;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
			if(now.x<R-1){
				next=now,next.x++;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
			if(now.y>0){
				next=now,next.y--;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
			if(now.y<C-1){
				next=now,next.y++;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
		}
		printf("%d\n",visit[dest.x][dest.y]-1);
	}
	return 0;
}
