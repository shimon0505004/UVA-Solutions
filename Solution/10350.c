#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 1000000000
#define SIZE 2005
int heap[SIZE],revheap[SIZE],heapsize;
int dis[SIZE];
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
int main(){
	char name[15];
	int time[SIZE][15];
	int m,n,i,j,k,d,min;
	while(fgets(name,15,stdin)!=NULL){
		scanf("%d%d",&n,&m);
		for(i=0;i<m*n;i++) dis[i]=INF;
		for(k=0;k<n-1;k++)
			for(i=0;i<m;i++)
				for(j=0;j<m;j++){
					scanf("%d",&d);
					time[m*k+i][j]=d;
				}
		for(i=0;i<m;i++) dis[i]=0;
		build_heap(m*n);
		while(heapsize>0){
			int now=extract_min();
			for(j=0;j<m;j++){
				int adj=m*(now/m+1)+j,t=dis[now]+time[now][j];
				if(t<dis[adj]) decrease_key(revheap[adj],t);
			}
		}
		min=INF;
		for(i=0;i<m;i++) if(dis[m*(n-1)+i]<min) min=dis[m*(n-1)+i];
		printf(name);
		printf("%d\n",min+2*(n-1));
		scanf(" ");
	}
	return 0;
}
