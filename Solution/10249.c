#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int heap[55],revheap[55],heapsize;
int table[55];
int M,N;
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
void max_heapify(int n){
	int l=(n<<1)+1,r=l+1,highest=n;
	if(l<heapsize&&table[heap[highest]]<table[heap[l]]) highest=l;
	if(r<heapsize&&table[heap[highest]]<table[heap[r]]) highest=r;
	if(highest!=n){
		int temp=heap[highest];
		heap[highest]=heap[n],heap[n]=temp;
		revheap[heap[n]]=n,revheap[heap[highest]]=highest;
		max_heapify(highest);
	}
}
int extract_max(){
	int result=heap[0];
	heap[0]=heap[--heapsize];
	revheap[heap[0]]=0;
	max_heapify(0);
	return result;
}
void build_heap(int n){
	int i;
	heapsize=n;
	for(i=0;i<heapsize;i++) heap[i]=revheap[i]=i;
	for(i=heapsize/2;i>=0;i--)
		max_heapify(i);
}
void increase_key(int n,int key){
	int parent=(n-1)>>1;
	table[heap[n]]=key;
	while(n>0&&table[heap[n]]>table[heap[parent]]){
		int temp=heap[n];
		heap[n]=heap[parent],heap[parent]=temp;
		revheap[heap[n]]=n,revheap[heap[parent]]=parent;
		n=parent,parent=(n-1)>>1;
	}
}
void insert_key(int whence,int key){
	heap[heapsize]=whence;
	revheap[whence]=heapsize;
	increase_key(heapsize++,key);
}
char make_seated(int n_member[],int seated[][105]){
	int i,j;
	int extracted[105],where[105];
	for(i=0;i<M;i++){
		for(j=0;j<n_member[i];j++){
			where[j]=extract_max();
			if((extracted[j]=table[where[j]])==0) return 0;
			seated[i][j]=where[j];
			extracted[j]--;
		}
		for(j=0;j<n_member[i];j++) insert_key(where[j],extracted[j]);
	}
	return 1;
}
int main(){
	int n_member[75],seated[75][105];
	int i,j;
	while(scanf("%d%d",&M,&N),M|N){
		int max=0;
		for(i=0;i<M;i++) scanf("%d",&n_member[i]),max=MAX(max,n_member[i]);
		for(i=0;i<N;i++) scanf("%d",&table[i]);
		build_heap(N);
		if(max<=N&&make_seated(n_member,seated)){
			puts("1");
			for(i=0;i<M;i++,puts("")){
				qsort(seated[i],n_member[i],sizeof(int),compar);
				printf("%d",seated[i][0]+1);
				for(j=1;j<n_member[i];j++)
					printf(" %d",seated[i][j]+1);
			}
		}else puts("0");
	}
	return 0;
}
