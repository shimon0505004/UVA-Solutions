#include<stdio.h>
struct QUERY{
	int from,to,num;
};
struct QUERY query[25];
int n_q,max;
char available(struct QUERY *q,int capacity[]){
	int i;
	for(i=q->from;i<q->to;i++) if(capacity[i]<q->num) return 0;
	return 1;
}
void dfs(int depth,int now,int capacity[]){
	int i;
	struct QUERY *q;
	if(depth==n_q){
		if(max<now) max=now;
		return;
	}
	q=&query[depth];
	if(available(q,capacity)){
		for(i=q->from;i<q->to;i++) capacity[i]-=q->num;
		dfs(depth+1,now+q->num*(q->to-q->from),capacity);
		for(i=q->from;i<q->to;i++) capacity[i]+=q->num;
	}
	dfs(depth+1,now,capacity);
}
int main(){
	int i;
	int cap,n;
	int capacity[7];
	while(scanf("%d%d%d",&cap,&n,&n_q),cap|n|n_q){
		for(i=0;i<n_q;i++) scanf("%d%d%d",&query[i].from,&query[i].to,&query[i].num);
		for(i=0;i<n;i++) capacity[i]=cap;
		max=-1;
		dfs(0,0,capacity);
		printf("%d\n",max);
	}
	return 0;
}
