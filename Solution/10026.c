#include<stdio.h>
#include<stdlib.h>
typedef struct WORK{
	int NO;
	int days;
	int fine;
}W;
int compar(const void *a,const void *b){
	W *w1=(W *)a,*w2=(W *)b;
	return w1->days*w2->fine-w2->days*w1->fine;
}
int main()
{
	int cases,N,i;
	W w[1005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d%d",&w[i].days,&w[i].fine);
			w[i].NO=i+1;
		}
		qsort(w,N,sizeof(W),compar);
		printf("%d",w[0].NO);
		for(i=1;i<N;i++)
			printf(" %d",w[i].NO);
		puts("");
		if(cases) puts("");
	}
	return 0;
}
