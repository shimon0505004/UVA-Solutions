#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int heap[1005],revheap[1005],heapsize;
int dis[1005];
struct ADJ{
	int n,dis;
	struct ADJ *next;
};
struct NODE{
	struct ADJ *adj;
};
void min_heapify(int n){
	int l=(n<<1)+1,r=l+1,lowest=n;
	if(r<heapsize&&dis[heap[r]]<dis[heap[lowest]]) lowest=r;
	if(l<heapsize&&dis[heap[l]]<dis[heap[lowest]]) lowest=l;
	if(lowest!=n){
		int temp=heap[lowest];
		heap[lowest]=heap[n],heap[n]=temp;
		revheap[heap[n]]=n,revheap[heap[lowest]]=lowest;
		min_heapify(lowest);
	}
}
void build_heap(int n){
	int i;
	heapsize=n;
	for(i=0;i<heapsize;i++) heap[i]=revheap[i]=i;
	for(i=heapsize/2;i>=0;i--)
		min_heapify(i);
}
int extract_min(){
	int result=heap[0];
	heap[0]=heap[--heapsize];
	revheap[heap[0]]=0;
	min_heapify(0);
	return result;
}
void decrease_key(int n,int key){
	int parent=(n-1)>>1;
	dis[heap[n]]=key;
	while(n>0&&dis[heap[n]]<dis[heap[parent]]){
		int temp=heap[n];
		heap[n]=heap[parent],heap[parent]=temp;
		revheap[heap[n]]=n,revheap[heap[parent]]=parent;
		n=parent,parent=(n-1)>>1;
	}
}
void insert(struct NODE *node,int adj,int dis){
	struct ADJ *adjptr=node->adj;
	node->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	node->adj->next=adjptr,node->adj->dis=dis,node->adj->n=adj;
}
int main(){
	struct NODE node[1005];
	int n,r,cases;
	int i;
	for(cases=1;scanf("%d%d",&n,&r)==2;cases++){
		memset(node,0,sizeof(node));
		n<<=1;
		while(r--){
			int from,to,dis;
			scanf("%d%d%d",&from,&to,&dis);
			insert(&node[from<<1],(to<<1)+1,dis);
			insert(&node[(from<<1)+1],to<<1,dis);
			insert(&node[to<<1],(from<<1)+1,dis);
			insert(&node[(to<<1)+1],from<<1,dis);
		}
		for(i=0;i<n;i++) dis[i]=1000000000;
		dis[0]=0;
		build_heap(n);
		while(heapsize>0){
			int now=extract_min();
			struct ADJ *adjptr;
			/*for(i=0;i<heapsize;i++) printf("%d(%d) ",heap[i],dis[heap[i]]);*/
			/*printf("%d(%d) %d\n",now>>1,now%2,dis[now]);*/
			for(adjptr=node[now].adj;adjptr!=NULL;adjptr=adjptr->next){
				int t=dis[now]+adjptr->dis;
				/*printf("%d(%d)->%d(%d)\n",now>>1,now%2,adjptr->n>>1,adjptr->n%2);*/
				if(t<dis[adjptr->n]) decrease_key(revheap[adjptr->n],t);
			}
		}
		printf("Set #%d\n",cases);
		if(dis[n-2]==1000000000) puts("?");
		else printf("%d\n",dis[n-2]);
	}
	return 0;
}
