#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int eleg_sum(int n,int seq[]){
	int sum[50],i;
	int half=n/2;
	sum[0]=seq[0];
	for(i=1;i<n;i++) sum[i]=sum[i-1]+seq[i];
	if(n%2==0) return (sum[n-1]-sum[half-1]*2)*2-(seq[half]-seq[half-1]);
	else{
		int a1,a2;
		a1=(sum[n-1]-sum[half-1]*2)*2-(seq[half]+seq[half+1]);
		a2=(sum[n-1]-sum[half]*2)*2+(seq[half]+seq[half-1]);
		return MAX(a1,a2);
	}
}
int main(){
	int T,cases;
	int n,seq[50],i;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&seq[i]);
		qsort(seq,n,sizeof(int),compar);
		printf("Case %d: %d\n",cases,eleg_sum(n,seq));
	}
	return 0;
}
