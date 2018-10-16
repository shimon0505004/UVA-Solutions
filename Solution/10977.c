#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(x)   ((x)*(x))
#define SIZE 205
#define SIZE_SQR 40005
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
	int R,C,r,c,n_obs,n_jig_puf,L,i,j;
	struct POINT src,dest;
	char map[SIZE][SIZE];
	int visit[SIZE][SIZE];
	while(scanf("%d%d",&R,&C),R|C){
		memset(map,0,sizeof(map));
		scanf("%d",&n_obs);
		while(n_obs--){
			scanf("%d%d",&r,&c);
			map[r][c]=1;
		}
		scanf("%d",&n_jig_puf);
		while(n_jig_puf--){
			int f_x,f_y,t_x,t_y;
			scanf("%d%d%d",&r,&c,&L);
			f_x=MAX(r-L,1),t_x=MIN(r+L,R);
			f_y=MAX(c-L,1),t_y=MIN(c+L,C);
			for(i=f_x;i<=t_x;i++)
				for(j=f_y;j<=t_y;j++)
					if(SQR(i-r)+SQR(j-c)<=SQR(L))
						map[i][j]=1;
		}
		src.x=1,src.y=1,dest.x=R,dest.y=C;
		memset(visit,0,sizeof(visit));
		head=tail=0;
		enqueue(src);
		visit[src.x][src.y]=1;
		while(!is_empty()){
			struct POINT now=dequeue();
			struct POINT next;
			if(now.x>1){
				next=now,next.x--;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
			if(now.x<R){
				next=now,next.x++;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
			if(now.y>1){
				next=now,next.y--;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
			if(now.y<C){
				next=now,next.y++;
				if(visit[next.x][next.y]==0&&map[next.x][next.y]==0){
					visit[next.x][next.y]=visit[now.x][now.y]+1;
					if(next.x==dest.x&&next.y==dest.y) break;
					enqueue(next);
				}
			}
		}
		if(visit[dest.x][dest.y]==0) puts("Impossible.");
		else printf("%d\n",visit[dest.x][dest.y]-1);
	}
	return 0;
}
