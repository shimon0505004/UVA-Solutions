#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 105
#define INF 1e8
struct POINT{
	double x,y;
};
double shortest[MAX];
int Heap[MAX],HeapSize,revHeap[MAX];
void MIN_HEAPIFY(int now){
	int l=(now<<1)+1,r=l+1,lowest=now;
	if(l<HeapSize&&shortest[Heap[l]]<shortest[Heap[lowest]]) lowest=l;
	if(r<HeapSize&&shortest[Heap[r]]<shortest[Heap[lowest]]) lowest=r;
	if(lowest!=now){
		int temp=Heap[now];
		Heap[now]=Heap[lowest],Heap[lowest]=temp;
		revHeap[Heap[now]]=now,revHeap[temp]=lowest;
		MIN_HEAPIFY(lowest);
	}
}
void HEAP_DECREASE_KEY(int inHeap,double key){
	int parent=(inHeap-1)>>1;
	shortest[Heap[inHeap]]=key;
	while(inHeap>0&&shortest[Heap[parent]]>shortest[Heap[inHeap]]){
		int temp=Heap[inHeap];
		Heap[inHeap]=Heap[parent],Heap[parent]=temp;
		revHeap[Heap[inHeap]]=inHeap,revHeap[Heap[parent]]=parent;
		inHeap=parent;
		parent=(inHeap-1)>>1;
	}
}
int EXTRACT_MIN(){
	int result=Heap[0];
	Heap[0]=Heap[--HeapSize];
	revHeap[Heap[0]]=0;
	MIN_HEAPIFY(0);
	return result;
}
void BUILD_HEAP(){
	int i;
	for(i=HeapSize>>1;i>=0;i--)
		MIN_HEAPIFY(i);
}
double dis(struct POINT *p1,struct POINT *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
int main(){
	int cases,n,i,j;
	struct POINT p[MAX];
	double distance[MAX][MAX],total;
	char visit[MAX];
	scanf("%d",&cases);
	while(cases--){
		memset(visit,0,sizeof(visit));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
			shortest[i]=INF;
			revHeap[i]=i;
			Heap[i]=i;
		}
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				distance[i][j]=distance[j][i]=dis(&p[i],&p[j]);
		shortest[0]=0;
		total=0;
		HeapSize=n;
		BUILD_HEAP();
		for(i=0;i<n;i++){
			int now=EXTRACT_MIN();
			total+=shortest[now];
			visit[now]=1;
			for(j=0;j<n;j++){
				if(visit[j]) continue;
				if(distance[now][j]<shortest[j])
					HEAP_DECREASE_KEY(revHeap[j],distance[now][j]);
			}
		}
		printf("%.2lf\n",total);
		if(cases) puts("");
	}
	return 0;
}
