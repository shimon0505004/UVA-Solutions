#include<stdio.h>
#include<string.h>
#define SIZE 105
int queue[SIZE],head,tail;
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
int prev[SIZE],cap[SIZE][SIZE];
int n,s,t;
char find_flow(){
	int i;
	char visit[SIZE];
	memset(visit,0,sizeof(visit));
	initial(),enqueue(s),visit[s]=1;
	while(!is_empty()){
		int now=dequeue();
		if(now==t) return 1;
		for(i=0;i<n;i++)
			if(cap[now][i]>0&&visit[i]==0){
				visit[i]=1;
				prev[i]=now;
				enqueue(i);
			}
	}
	return 0;
}
int main(){
	int c,cases,flow,update;
	for(cases=1;scanf("%d",&n),n;cases++){
		scanf("%d%d%d",&s,&t,&c);
		s--,t--;
		memset(cap,0,sizeof(cap));
		while(c--){
			int from,to,capacity;
			scanf("%d%d%d",&from,&to,&capacity);
			cap[from-1][to-1]+=capacity;
			cap[to-1][from-1]+=capacity;
		}
		flow=0;
		while(find_flow()){
			int p,q;
			update=10;
			for(p=t;p!=s;p=q){
				q=prev[p];
				if(cap[q][p]<update)
					update=cap[q][p];
			}
			flow+=update;
			for(p=t;p!=s;p=q){
				q=prev[p];
				cap[p][q]+=update;
				cap[q][p]-=update;
			}
		}
		printf("Network %d\n",cases);
		printf("The bandwidth is %d.\n",flow);
		puts("");
	}
	return 0;
}
