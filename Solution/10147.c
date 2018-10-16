#include<stdio.h>
#define SWAP(a,b) {struct NODE t=a;a=b;b=t;}
struct POINT{
	int x,y;
};
struct NODE{
	int from,to;
	int dis;
};
struct NODE node[760*760];
int n_node;
void MIN_HEAPIFY(int now){
	int lowest=now,l=(now<<1)+1,r=l+1;
	if(l<n_node&&node[l].dis<node[lowest].dis) lowest=l;
	if(r<n_node&&node[r].dis<node[lowest].dis) lowest=r;
	if(lowest!=now){
		SWAP(node[lowest],node[now]);
		MIN_HEAPIFY(lowest);
	}
}
void BUILD_HEAP(){
	int i;
	for(i=n_node>>1;i>=0;i--)
		MIN_HEAPIFY(i);
}
struct NODE EXTRACT_MIN(){
	struct NODE result=node[0];
	node[0]=node[--n_node];
	MIN_HEAPIFY(0);
	return result;
}
int distance(struct POINT *p1,struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return x*x+y*y;
}
int parent[760];
void link(int dest,int src){
	parent[src]=dest;
}
int find_root(int n){
	if(parent[n]!=n) parent[n]=find_root(parent[n]);
	return parent[n];
}
int main(){
	int N,M;
	int cases,i,j;
	char start;
	struct POINT p[760];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		n_node=0;
		for(i=1;i<=N;i++) scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%d",&M);
		for(i=1;i<=N;i++) parent[i]=i;
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			link(find_root(a),find_root(b));
		}
		for(i=2;i<=N;i++)
			for(j=1;j<i;j++){
				node[n_node].from=i;
				node[n_node].to=j;
				node[n_node].dis=distance(&p[i],&p[j]);
				n_node++;
			}
		BUILD_HEAP();
		start=0;
		while(n_node!=0){
			struct NODE node=EXTRACT_MIN();
			if(find_root(node.from)!=find_root(node.to)){
				printf("%d %d\n",node.from,node.to);
				start=1;
				link(find_root(node.from),find_root(node.to));
			}
		}
		if(start==0) puts("No new highways need");
		if(cases) puts("");
	}
	return 0;
}
