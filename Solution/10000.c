#include<stdio.h>
#include<string.h>
#define Q_MAX 500
#define MAX 105
int queue[Q_MAX];
int head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[tail++]=n;
	tail%=Q_MAX;
}
int dequeue(){
	int result=queue[head++];
	head%=Q_MAX;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int n_node,S,from,to;
	char map[MAX][MAX];
	int depth[MAX],cases,max,maxi,i;
	for(cases=1;scanf("%d",&n_node),n_node;cases++){
		if(n_node>200) n_node/=0;
		memset(map,0,sizeof(map));
		for(i=1;i<=n_node;i++) depth[i]=-1;
		scanf("%d",&S);
		while(scanf("%d%d",&from,&to),from) map[from][to]=1;
		initial();
		depth[S]=0;
		enqueue(S);
		while(!is_empty()){
			int now=dequeue();
			for(i=1;i<=n_node;i++)
				if(map[now][i]&&depth[i]<depth[now]+1){
					enqueue(i);
					depth[i]=depth[now]+1;
				}
		}
		max=-1;
		for(i=1;i<=n_node;i++)
			if(depth[i]>max) max=depth[i],maxi=i;
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cases,S,max,maxi);
	}
	return 0;
}
