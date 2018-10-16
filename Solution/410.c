#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int S,C;
	int seq[10];
	int cases;
	int total,ans;
	int i;
	for(cases=1;scanf("%d%d",&C,&S)==2;cases++){
		total=0;
		for(i=0;i<S;i++) scanf("%d",&seq[i]),total+=seq[i];
		qsort(seq,S,sizeof(int),compar);
		printf("Set #%d\n",cases);
		ans=0;
		for(i=0;i<C;i++){
			int W_chamber=0;
			int less=S-2*C+i,more=S-1-i;
			printf("%2d:",i);
			if(less>=0) printf(" %d",seq[less]),W_chamber+=seq[less];
			if(more>=0) printf(" %d",seq[more]),W_chamber+=seq[more];
			ans+=abs(W_chamber*C-total);
			puts("");
		}
		printf("IMBALANCE = %.5lf\n\n",(double)ans/C);
	}
	return 0;
}
