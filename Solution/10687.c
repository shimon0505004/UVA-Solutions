#include<stdio.h>
#include<string.h>
#define SIZE 1005
struct POINT{
	int x,y;
};
int dis_sqr(struct POINT *p1,struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return x*x+y*y;
}
int queue[SIZE];
int head,tail;
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
int main(){
	struct POINT p[SIZE];
	int adj[SIZE][2];
	int N,near_j,near,sec_near,sec_near_j;
	int i,j,rest;
	char visit[SIZE];
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++) scanf("%d%d",&p[i].x,&p[i].y);
		for(i=0;i<N;i++){
			near=sec_near=1000;
			for(j=0;j<N;j++){
				int d=dis_sqr(&p[i],&p[j]);
				if(i==j) continue;
				if(d<near) sec_near=near,sec_near_j=near_j,near_j=j,near=d;
				else if(d==near){
					if(p[near_j].x>p[j].x) sec_near=near,sec_near_j=near_j,near_j=j,near=d;
					else if(p[near_j].x==p[j].x&&p[near_j].y>p[j].y) sec_near=near,sec_near_j=near_j,near_j=j,near=d;
				}
				if(j==near_j) continue;
				if(d<sec_near) sec_near_j=j,sec_near=d;
				else if(d==sec_near){
					if(p[sec_near_j].x>p[j].x) sec_near_j=j,sec_near=d;
					else if(p[sec_near_j].x==p[j].x&&p[sec_near_j].y>p[j].y) sec_near_j=j,sec_near=d;
				}
			}
			adj[i][0]=near_j,adj[i][1]=sec_near_j;
		}
		memset(visit,0,sizeof(visit));
		head=tail=0;
		enqueue(0);
		visit[0]=1;
		rest=N-1;
		while(!is_empty()){
			int now=dequeue();
			if(visit[adj[now][0]]==0){
				rest--;
				visit[adj[now][0]]=1;
				enqueue(adj[now][0]);
			}
			if(visit[adj[now][1]]==0){
				rest--;
				visit[adj[now][1]]=1;
				enqueue(adj[now][1]);
			}
		}
		if(rest==0) puts("All stations are reachable.");
		else puts("There are stations that are unreachable.");
	}
	return 0;
}
