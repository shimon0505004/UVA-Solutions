#include<stdio.h>
#define MAXN 1000005
int main(){
	int i,j,count=0;
	int M[MAXN]={0},q;
	int minfactor[MAXN]={0};
	int N,m;
	for(i=2;i<MAXN/2;i++){
		if(minfactor[i]) continue;
		for(j=2;i*j<MAXN;j++)
			if(minfactor[i*j]==0) minfactor[i*j]=i;
	}
	M[1]=1;
	for(i=2;i<MAXN;i++){
		m=minfactor[i];
		M[i]=M[i-1];
		if(m==0) M[i]--;
		else{
			q=i/m;
			if(M[q]!=M[q-1]&&q%m!=0) M[i]+=M[q-1]-M[q];
		}
	}
	while(scanf("%d",&N),N) printf("%8d%8d%8d\n",N,M[N]-M[N-1],M[N]);
	return 0;
}
