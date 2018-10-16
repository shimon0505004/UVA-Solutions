#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define INF 1000000000
struct ADJACENT{
	int delay,n;
	struct ADJACENT *next;
};
struct INTERSEC{
	int shortest,prev;
	struct ADJACENT *adj;
};
struct INTERSEC s[MAX];
void clear(struct ADJACENT *adj){
	if(adj!=NULL){
		clear(adj->next);
		free(adj);
	}
}
int Heap[MAX],HeapSize,revHeap[MAX];
void MAX_HEAPIFY(int now){
	int l=(now<<1),r=(now<<1)+1,lowest=now;
	if(l<=HeapSize&&s[Heap[l]].shortest<s[Heap[now]].shortest) lowest=l;
	if(r<=HeapSize&&s[Heap[r]].shortest<s[Heap[lowest]].shortest) lowest=r;
	if(lowest!=now){
		int temp=Heap[now];
		Heap[now]=Heap[lowest],Heap[lowest]=temp;
		revHeap[Heap[now]]=now,revHeap[temp]=lowest;
		MAX_HEAPIFY(lowest);
	}
}
void HEAP_DECREASE_KEY(int inHeap,int key){
	int parent=inHeap>>1;
	s[Heap[inHeap]].shortest=key;
	while(inHeap>1&&s[Heap[parent]].shortest>s[Heap[inHeap]].shortest){
		int temp=Heap[inHeap];
		Heap[inHeap]=Heap[parent],Heap[parent]=temp;
		revHeap[Heap[inHeap]]=inHeap,revHeap[Heap[parent]]=parent;
		inHeap=parent;
		parent=inHeap>>1;
	}
}
void printPath(int now){
	if(s[now].prev) printPath(s[now].prev);
	printf(" %d",now);
}
int main(){
	int n,S,T,i,from,to,t,connections,cases;
	int w;
	struct ADJACENT **adj[MAX],*adjPtr;
	for(cases=1;scanf("%d",&n),n;cases++){
		for(i=1;i<=n;i++){
			s[i].shortest=INF;
			s[i].prev=0;
			s[i].adj=NULL;
			adj[i]=&(s[i].adj);
			Heap[i]=i,revHeap[i]=i;
			scanf("%d",&connections);
			while(connections--){
				scanf("%d%d",&to,&w);
				*(adj[i])=(struct ADJACENT *)malloc(sizeof(struct ADJACENT));
				(*(adj[i]))->n=to,(*(adj[i]))->delay=w,(*(adj[i]))->next=NULL;
				adj[i]=&((*(adj[i]))->next);
			}
		}
		scanf("%d%d",&S,&T);
		HeapSize=n;
		s[S].shortest=0;
		for(i=HeapSize/2;i>0;i--) MAX_HEAPIFY(i);
		for(i=1;i<=n;i++){
			int now=Heap[1],j;
			if(now==T) break;
			Heap[1]=Heap[HeapSize--],revHeap[Heap[1]]=1;
			MAX_HEAPIFY(1);
			for(adjPtr=s[now].adj;adjPtr!=NULL;adjPtr=adjPtr->next)
				if((t=s[now].shortest+adjPtr->delay)<s[adjPtr->n].shortest){
					HEAP_DECREASE_KEY(revHeap[adjPtr->n],t);
					s[adjPtr->n].prev=now;
				}
		}
		printf("Case %d: Path =",cases);
		printPath(T);
		printf("; %d second delay\n",s[T].shortest);
		for(i=1;i<=n;i++) clear(s[i].adj);
	}
	return 0;
}
