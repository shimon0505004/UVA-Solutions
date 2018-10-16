#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
void printkuPellaKeS(int seq[],int subsum[],int from,int end){
	int i,min=2147483647,leftsum=-2147483647,root;
	int left,right;
	if(from==end){
		printf("%d",seq[from]);
		return;
	}
	for(i=from;i<=end;i++){
		int d;
		if(i<end&&seq[i]==seq[i+1]) continue;
		left=subsum[i-1]-subsum[from-1];
		right=subsum[end]-subsum[i];
		d=abs(left-right);
		if(d<min) root=i,min=d,leftsum=left;
		else if(d==min&&left>leftsum) root=i,leftsum=left;
	}
	printf("%d(",seq[root]);
	if(root>from) printkuPellaKeS(seq,subsum,from,root-1);
	if(root>from&&root<end) printf(",");
	if(root<end) printkuPellaKeS(seq,subsum,root+1,end);
	printf(")");
}
int main(){
	int cases,T,n,i;
	int seq[1005];
	int subsum[1005];
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&seq[i]);
		qsort(seq+1,n,sizeof(int),compar);
		subsum[0]=0;
		for(i=1;i<=n;i++) subsum[i]=subsum[i-1]+seq[i];
		printf("Case #%d: ",cases);
		printkuPellaKeS(seq,subsum,1,n);
		puts("");
	}
	return 0;
}
