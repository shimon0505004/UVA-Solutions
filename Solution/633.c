#include<stdio.h>
#include<string.h>
#define SIZE 5000
char visit[3][45][45];
int depth[SIZE];
int queue[SIZE],head,tail;
int sx,sy,ex,ey,n;
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE;
}
int dequeue(){
	int result=queue[tail++];
	tail%=SIZE;
	return result;
}
char is_empty(){
	return head==tail;
}
void initial(){
	head=tail=0;
}
int map(int type,int x,int y){
	return type*1600+x*40+y;
}
int gettype(int pos){
	return pos/1600;
}
void getpos(int pos,int *x,int *y){
	pos%=1600;
	*x=pos/40,*y=pos%40;
}
int cal_min_dis(){
	int i,end[3];
	int now;
	for(i=0;i<3;i++) end[i]=map(i,ex,ey);
	initial();
	for(i=0;i<3;i++) enqueue(map(i,sx,sy));
	while(!is_empty()){
		int type,x,y;
		int nx,ny;
		now=dequeue();
		type=gettype(now);
		getpos(now,&x,&y);
		if(now==end[0]||now==end[1]||now==end[2]) break;
		if(type!=0){
			if(x>0){
				if(y>1){
					nx=x-1,ny=y-2;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
				if(y+2<n){
					nx=x-1,ny=y+2;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
			}
			if(x>1){
				if(y>0){
					nx=x-2,ny=y-1;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
				if(y+1<n){
					nx=x-2,ny=y+1;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
			}
			if(x+1<n){
				if(y>1){
					nx=x+1,ny=y-2;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
				if(y+2<n){
					nx=x+1,ny=y+2;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}

			}
			if(x+2<n){
				if(y>0){
					nx=x+2,ny=y-1;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
				if(y+1<n){
					nx=x+2,ny=y+1;
					if(visit[0][nx][ny]==0){
						visit[0][nx][ny]=1;
						depth[map(0,nx,ny)]=depth[map(type,x,y)]+1;
						enqueue(map(0,nx,ny));
					}
				}
			}
		}
		if(type!=1){
			if(x>1&&y>1){
				nx=x-2,ny=y-2;
				if(visit[1][nx][ny]==0){
					visit[1][nx][ny]=1;
					depth[map(1,nx,ny)]=depth[map(type,x,y)]+1;
					enqueue(map(1,nx,ny));
				}
			}
			if(x>1&&y+2<n){
				nx=x-2,ny=y+2;
				if(visit[1][nx][ny]==0){
					visit[1][nx][ny]=1;
					depth[map(1,nx,ny)]=depth[map(type,x,y)]+1;
					enqueue(map(1,nx,ny));
				}
			}
			if(x+2<n&&y>1){
				nx=x+2,ny=y-2;
				if(visit[1][nx][ny]==0){
					visit[1][nx][ny]=1;
					depth[map(1,nx,ny)]=depth[map(type,x,y)]+1;
					enqueue(map(1,nx,ny));
				}
			}
			if(x+2<n&&y+2<n){
				nx=x+2,ny=y+2;
				if(visit[1][nx][ny]==0){
					visit[1][nx][ny]=1;
					depth[map(1,nx,ny)]=depth[map(type,x,y)]+1;
					enqueue(map(1,nx,ny));
				}
			}
		}
		if(type!=2){
			nx=n-x-1,ny=y;
			if(visit[2][nx][ny]==0){
				visit[2][nx][ny]=1;
				depth[map(2,nx,ny)]=depth[map(type,x,y)]+1;
				enqueue(map(2,nx,ny));
			}
			nx=x,ny=n-y-1;
			if(visit[2][nx][ny]==0){
				visit[2][nx][ny]=1;
				depth[map(2,nx,ny)]=depth[map(type,x,y)]+1;
				enqueue(map(2,nx,ny));
			}
		}
	}
	for(i=0;i<3;i++)
		if(now==end[i]) return depth[now];
	return -1;
}
int main(){
	int i,result;
	int ox,oy;
	while(scanf("%d",&n),n){
		n*=2;
		memset(visit,0,sizeof(visit));
		memset(depth,0,sizeof(depth));
		scanf("%d%d",&sx,&sy),sx--,sy--;
		scanf("%d%d",&ex,&ey),ex--,ey--;
		while(scanf("%d%d",&ox,&oy),ox--|oy--)
			for(i=0;i<3;i++)
				visit[i][ox][oy]=1;
		result=cal_min_dis();
		if(result<0) puts("Solution doesn't exist");
		else printf("Result : %d\n",result);
	}
	return 0;
}
