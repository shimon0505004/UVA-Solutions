#include<stdio.h>
#include<stdlib.h>
#define SIZE 505
#define UBOUND 2147483647
int heap[SIZE],revheap[SIZE],heapsize;
int dis[SIZE];
struct ADJ{
	int n,dis;
	struct ADJ *next;
};
struct NODE{
	struct ADJ *adj;
};
void min_heapify(int n){
	int l=(n<<1)+1,r=l+1,lowest=n;
	if(l<heapsize&&dis[heap[l]]<dis[heap[lowest]]) lowest=l;
	if(r<heapsize&&dis[heap[r]]<dis[heap[lowest]]) lowest=r;
	if(lowest!=n){
		int temp;
		temp=heap[n],heap[n]=heap[lowest],heap[lowest]=temp;
		revheap[heap[n]]=n,revheap[heap[lowest]]=lowest;
		min_heapify(lowest);
	}
}
void build_heap(int n){
	int i;
	heapsize=n;
	for(i=0;i<heapsize;i++) revheap[i]=heap[i]=i;
	for(i=heapsize/2;i>=0;i--)
		min_heapify(i);
}
void decrease_key(int inheap,int key){
	int parent=(inheap-1)>>1;
	dis[heap[inheap]]=key;
	while(inheap>0&&dis[heap[inheap]]<dis[heap[parent]]){
		int temp;
		temp=heap[inheap],heap[inheap]=heap[parent],heap[parent]=temp;
		revheap[heap[inheap]]=inheap,revheap[heap[parent]]=parent;
		inheap=parent,parent=(inheap-1)>>1;
	}
}
int extract_min(){
	int result=heap[0];
	heap[0]=heap[--heapsize];
	revheap[heap[0]]=0;
	min_heapify(0);
	return result;
}
void insert(struct NODE *n,int adj,int dis){
	struct ADJ *tmpadj=n->adj;
	n->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	n->adj->next=tmpadj;
	n->adj->n=adj;
	n->adj->dis=dis;
}
int main(){
	int n,m,d,from,to,last,last2,t,i,cases,s;
	struct NODE node[SIZE];
	int pair[250005][3];
	for(cases=1;scanf("%d%d",&n,&m),n|m;cases++){
		for(i=0;i<n;i++) node[i].adj=NULL;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&from,&to,&d),from--,to--;
			insert(&node[from],to,d);
			insert(&node[to],from,d);
			pair[i][0]=from,pair[i][1]=to,pair[i][2]=d;
		}
		for(i=0;i<n;i++) dis[i]=UBOUND;
		dis[0]=0;
		build_heap(n);
		while(heapsize>0){
			struct ADJ *adjPtr;
			int now=extract_min();
			for(adjPtr=node[now].adj;adjPtr!=NULL;adjPtr=adjPtr->next)
				if(dis[now]+adjPtr->dis<dis[adjPtr->n])
					decrease_key(revheap[adjPtr->n],dis[now]+adjPtr->dis);
		}
		last=0,t=0;
		for(i=1;i<n;i++)
			if(dis[i]*2>t) t=dis[i]*2,last=i;
		last2=-1;
		for(i=0;i<m;i++)
			if((s=dis[pair[i][0]]+dis[pair[i][1]]+pair[i][2])>t)
				last=pair[i][0],last2=pair[i][1],t=s;
		printf("System #%d\n",cases);
		if(t==dis[last]*2) printf("The last domino falls after %d.0 seconds, at key domino %d.\n",t/2,last+1);
		else printf("The last domino falls after %d.%d seconds, between key dominoes %d and %d.\n",t/2,(t%2)*5,last+1,last2+1);
		puts("");
	}
	return 0;
}
