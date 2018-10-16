#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
struct ADJ{
	struct ADJ *next;
	int v;
	double R,D;
};
struct VERTEX{
	struct ADJ *adj;
};
void insertAdj(struct VERTEX *v,int to,double R,double D){
	struct ADJ *adjPtr=v->adj;
	v->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	v->adj->next=adjPtr;
	v->adj->v=to,v->adj->R=R,v->adj->D=D;
}
int Heap[105],inHeap[105],HeapSize;
double shortest[105];
int S,T,N;
void MIN_HEAPIFY(int now){
	int l=now<<1,r=l+1,lowest=now;
	if(l<=HeapSize&&shortest[Heap[l]]<shortest[Heap[lowest]]) lowest=l;
	if(r<=HeapSize&&shortest[Heap[r]]<shortest[Heap[lowest]]) lowest=r;
	if(lowest!=now){
		int temp=Heap[now];
		Heap[now]=Heap[lowest],Heap[lowest]=temp;
		inHeap[Heap[now]]=now,inHeap[Heap[lowest]]=lowest;
		MIN_HEAPIFY(lowest);
	}
}
void HEAP_DECREASE_KEY(int now,double key){
	int index=inHeap[now],parent=index>>1;
	shortest[now]=key;
	while(index>1&&shortest[Heap[parent]]>shortest[Heap[index]]){
		int temp=Heap[index];
		Heap[index]=Heap[parent],Heap[parent]=temp;
		inHeap[Heap[index]]=index,inHeap[Heap[parent]]=parent;
		index=parent,parent=index>>1;
	}
}
int EXTRACT_MIN(){
	int result=Heap[1];
	Heap[1]=Heap[HeapSize--];
	inHeap[Heap[1]]=1;
	MIN_HEAPIFY(1);
	return result;
}
void BUILD_HEAP(){
	int i;
	for(i=HeapSize>>1;i>0;i--) MIN_HEAPIFY(i);
}
void printRoute(int prev[],int now){
	if(prev[now]!=S) printRoute(prev,prev[now]);
	printf(" %d",now);
}
void freeAdj(struct ADJ *adj){
	if(adj->next!=NULL) freeAdj(adj->next);
	free(adj);
}
int main(){
	int E,from,to;
	int i,j,k,now;
	struct VERTEX v[105];
	double temperature[105][105],R,D,t,HT;
	int prev[105];
	while(scanf("%d%d",&N,&E)==2){
		scanf("%d%d",&S,&T);
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				temperature[i][j]=100;
		for(i=1;i<=N;i++){
			v[i].adj=NULL;
			shortest[i]=1e8;
			Heap[i]=i,inHeap[i]=i;
			prev[i]=0;
		}
		while(E--){
			scanf("%d%d%lf%lf",&from,&to,&R,&D);
			if(R<temperature[from][to]) temperature[from][to]=temperature[to][from]=R;
			insertAdj(&v[from],to,R,D),insertAdj(&v[to],from,R,D);
		}
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<i;j++)
					if((t=MAX(temperature[i][k],temperature[k][j]))<temperature[i][j])
						temperature[i][j]=temperature[j][i]=t;
		HT=temperature[S][T];
		shortest[S]=0;
		HeapSize=N;
		BUILD_HEAP();
		while((now=EXTRACT_MIN())!=T){
			struct ADJ *adjPtr;
			for(adjPtr=v[now].adj;adjPtr!=NULL;adjPtr=adjPtr->next)
				if(adjPtr->R<HT+1e-5&&shortest[adjPtr->v]>(t=shortest[now]+adjPtr->D)){
					prev[adjPtr->v]=now;
					HEAP_DECREASE_KEY(adjPtr->v,t);
				}
		}
		printf("%d",S);
		printRoute(prev,T);
		puts("");
		printf("%.1lf %.1lf\n",shortest[T],HT);
		for(i=1;i<=N;i++)
			if(v[i].adj!=NULL)
				freeAdj(v[i].adj);
	}
	return 0;
}
