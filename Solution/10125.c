#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int seq[1005];
	int N,i,j,k,find;
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++) scanf("%d",&seq[i]);
		qsort(seq,N,sizeof(int),compar);
		for(i=N-1;i>=0;i--){
			for(j=0;j<N;j++){
				if(j==i) continue;
				for(k=0;k<j;k++){
					if(k==i||seq[j]+seq[k]==0) continue;
					find=seq[i]-seq[j]-seq[k];
					if(find==seq[j]||find==seq[k]) continue;
					if(bsearch(&find,seq,N,sizeof(int),compar)!=NULL) break;
				}
				if(k<j) break;
			}
			if(j<N) break;
		}
		if(i>=0) printf("%d\n",seq[i]);
		else puts("no solution");
	}
	return 0;
}
