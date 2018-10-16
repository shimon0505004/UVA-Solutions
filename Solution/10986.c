#include<stdio.h>
#include<stdlib.h>
#define MAX 20050
#define INF 2000000000
struct ADJACENT{
	int time,n;
	struct ADJACENT *next;
};
struct SERVER{
	int shortest;
	struct ADJACENT *adj;
};
struct SERVER s[MAX];
void clear(struct ADJACENT *adj){
	if(adj!=NULL){
		clear(adj->next);
		free(adj);
	}
}
int Heap[MAX],HeapSize,revHeap[MAX];
void MAX_HEAPIFY(int now){
	int l=(now<<1)+1,r=(now<<1)+2,lowest=now;
	if(l<HeapSize&&s[Heap[l]].shortest<s[Heap[now]].shortest) lowest=l;
	if(r<HeapSize&&s[Heap[r]].shortest<s[Heap[lowest]].shortest) lowest=r;
	if(lowest!=now){
		int temp=Heap[now];
		Heap[now]=Heap[lowest],Heap[lowest]=temp;
		revHeap[Heap[now]]=now,revHeap[temp]=lowest;
		MAX_HEAPIFY(lowest);
	}
}
void HEAP_DECREASE_KEY(int inHeap,int key){
	int parent=(inHeap-1)>>1;
	s[Heap[inHeap]].shortest=key;
	while(inHeap>0&&s[Heap[parent]].shortest>s[Heap[inHeap]].shortest){
		int temp=Heap[inHeap];
		Heap[inHeap]=Heap[parent],Heap[parent]=temp;
		revHeap[Heap[inHeap]]=inHeap,revHeap[Heap[parent]]=parent;
		inHeap=parent;
		parent=(inHeap-1)>>1;
	}
}
int main(){
	int N,cases,n,m,S,T,w,i,from,to,t;
	struct ADJACENT **adj[MAX],*adjPtr;
	scanf("%d",&N);
	for(cases=1;cases<=N;cases++){
		scanf("%d%d%d%d",&n,&m,&S,&T);
		for(i=0;i<n;i++){
			s[i].shortest=INF;
			s[i].adj=NULL;
			adj[i]=&(s[i].adj);
			Heap[i]=i,revHeap[i]=i;
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&from,&to,&w);
			*(adj[from])=(struct ADJACENT *)malloc(sizeof(struct ADJACENT));
			(*(adj[from]))->n=to,(*(adj[from]))->time=w,(*(adj[from]))->next=NULL;
			adj[from]=&((*(adj[from]))->next);
			*(adj[to])=(struct ADJACENT *)malloc(sizeof(struct ADJACENT));
			(*(adj[to]))->n=from,(*(adj[to]))->time=w,(*(adj[to]))->next=NULL;
			adj[to]=&((*(adj[to]))->next);
		}
		HeapSize=n;
		s[S].shortest=0;
		for(i=HeapSize/2;i>=0;i--) MAX_HEAPIFY(i);
		for(i=0;i<n;i++){
			int now=Heap[0],j;
			if(now==T||s[now].shortest==INF) break;
			Heap[0]=Heap[--HeapSize],revHeap[Heap[0]]=0;
			MAX_HEAPIFY(0);
			for(adjPtr=s[now].adj;adjPtr!=NULL;adjPtr=adjPtr->next){
				if((t=s[now].shortest+adjPtr->time)<s[adjPtr->n].shortest)
					HEAP_DECREASE_KEY(revHeap[adjPtr->n],t);
			}
		}
		printf("Case #%d: ",cases);
		if(s[T].shortest==INF) puts("unreachable");
		else printf("%d\n",s[T].shortest);
		for(i=0;i<n;i++) clear(s[i].adj);
	}
	return 0;
}
