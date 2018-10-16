#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SIZE 205
int queue[SIZE],head,tail;
int cap[SIZE][SIZE];
int prev[SIZE];
char visit[SIZE];
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE;
}
int dequeue(){
	int res=queue[tail++];
	tail%=SIZE;
	return res;
}
char is_empty(){
	return head==tail;
}
int n;
char find_flow(){
	int i;
	initial(),enqueue(0),visit[0]=1;
	memset(visit,0,sizeof(visit));
	while(!is_empty()){
		int now=dequeue();
		if(now==n-1) return 1;
		for(i=0;i<n;i++)
			if(visit[i]==0&&cap[now][i]>0){
				prev[i]=now;
				visit[i]=1;
				enqueue(i);
			}
	}
	return 0;
}
int main(){
	int flow,N,M,i;
	while(scanf("%d",&N)==1){
		int B,b,D,d;
		memset(cap,0,sizeof(cap));
		for(i=1;i<=N;i++) scanf("%d",&cap[i*2-1][i*2]);
		scanf("%d",&M);
		while(M--){
			int from,to,c;
			scanf("%d%d%d",&from,&to,&c);
			cap[from*2][to*2-1]=c;
		}
		scanf("%d%d",&B,&D);
		while(B--) scanf("%d",&b),cap[0][b*2-1]=2147483647;
		while(D--) scanf("%d",&d),cap[d*2][2*N+1]=2147483647;
		n=2*N+2;
		flow=0;
		while(find_flow()){
			int p,q,update=2147483647;
			for(p=n-1;p!=0;p=q)
				q=prev[p],update=MIN(update,cap[q][p]);
			flow+=update;
			for(p=n-1;p!=0;p=q)
				q=prev[p],cap[q][p]-=update,cap[p][q]+=update;
		}
		printf("%d\n",flow);
	}
	return 0;
}
