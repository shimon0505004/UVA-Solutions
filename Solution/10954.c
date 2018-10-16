#include<stdio.h>
#define MIN 5000
long long Heap[MIN];
int HeapSize;
void MIN_HEAPIFY(int now){
	int l=(now<<1)+1,r=(now<<1)+2,lowest=now;
	if(l<HeapSize&&Heap[l]<Heap[lowest]) lowest=l;
	if(r<HeapSize&&Heap[r]<Heap[lowest]) lowest=r;
	if(lowest!=now){
		long long temp=Heap[now];
		Heap[now]=Heap[lowest],Heap[lowest]=temp;
		MIN_HEAPIFY(lowest);
	}
}
int EXTRACT_MIN(){
	long long result=Heap[0];
	Heap[0]=Heap[--HeapSize];
	MIN_HEAPIFY(0);
	return result;
}
int main(){
	int N,i;
	long long Sum,now;
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++) scanf("%d",&Heap[i]);
		HeapSize=N;
		for(i=HeapSize/2;i>=0;i--) MIN_HEAPIFY(i);
		Sum=0;
		while(HeapSize>1){
			now=EXTRACT_MIN();
			now+=Heap[0];
			Heap[0]=now;
			MIN_HEAPIFY(0);
			Sum+=now;
		}
		printf("%lld\n",Sum);
	}
	return 0;
}
