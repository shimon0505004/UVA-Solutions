#include<stdio.h>
#define Ubound 10005
#define MIN(a,b) ((a)>(b)?(b):(a))
int search(int mintail[],int seq[],int U,int key){
	int L=0,mid=(U+L)/2;
	while(L!=mid){
		if(key>seq[mintail[mid]]) L=mid;
		else U=mid;
		mid=(L+U)/2;
	}
	return mid+1;
}
void build_mintail(int N,int seq[],int mintail[],int LIS[]){
	int i,s;
	mintail[0]=-2147483647;
	for(i=1;i<=N;i++) mintail[i]=N;
	for(i=0;i<N;i++){
		s=search(mintail,seq,i+1,seq[i]);
		mintail[s]=i;
		LIS[i]=s;
	}
}
int main(){
	int mintail[Ubound],r_mintail[Ubound];
	int seq[Ubound],r_seq[Ubound];
	int LIS[Ubound],r_LIS[Ubound];
	int N,i,max,t;
	while(scanf("%d",&N)==1){
		for(i=0;i<N;i++) scanf("%d",&seq[i]),r_seq[N-i-1]=seq[i];
		seq[N]=r_seq[N]=2147483647;
		build_mintail(N,seq,mintail,LIS);
		build_mintail(N,r_seq,r_mintail,r_LIS);
		max=0;
		for(i=0;i<N-max;i++)
			if((t=MIN(LIS[i],r_LIS[N-1-i]))>max) max=t;
		printf("%d\n",max*2-1);
	}
	return 0;
}
