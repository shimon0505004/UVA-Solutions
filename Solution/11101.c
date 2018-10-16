#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 4000005
int queue[SIZE],head,tail;
int block[2001][2001];
int map(int x,int y){
	return x*2001+y;
}
void unmap(int n,int *x,int *y){
	*x=n/2001,*y=n%2001;
}
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
int min_dis(){
	int n,x,y,nx,ny;
	while(!is_empty()){
		n=dequeue();
		unmap(n,&x,&y);
		if(x<2000){
			nx=x+1,ny=y;
			if(block[nx][ny]<0) return block[x][y];
			else if(block[nx][ny]==0)
				block[nx][ny]=block[x][y]+1,enqueue(map(nx,ny));
		}
		if(y<2000){
			nx=x,ny=y+1;
			if(block[nx][ny]<0) return block[x][y];
			else if(block[nx][ny]==0)
				block[nx][ny]=block[x][y]+1,enqueue(map(nx,ny));
		}
		if(x>0){
			nx=x-1,ny=y;
			if(block[nx][ny]<0) return block[x][y];
			else if(block[nx][ny]==0)
				block[nx][ny]=block[x][y]+1,enqueue(map(nx,ny));
		}
		if(y>0){
			nx=x,ny=y-1;
			if(block[nx][ny]<0) return block[x][y];
			else if(block[nx][ny]==0)
				block[nx][ny]=block[x][y]+1,enqueue(map(nx,ny));
		}
	}
	return 0;
}
int main(){
	int peri1,peri2;
	int x,y;
	while(scanf("%d",&peri1),peri1){
		memset(block,0,sizeof(block));
		while(peri1--){
			scanf("%d%d",&x,&y);
			block[x][y]=-1;
		}
		initial();
		scanf("%d",&peri2);
		while(peri2--){
			scanf("%d%d",&x,&y);
			block[x][y]=1;
			enqueue(map(x,y));
		}
		printf("%d\n",min_dis());
	}
	return 0;
}
