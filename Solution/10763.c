#include<stdio.h>
#include<stdlib.h>
#define max 500002
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main()
{
	int candidates[2][max];
	int N,i;
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++)
			scanf("%d%d",&candidates[0][i],&candidates[1][i]);
		qsort(candidates[0],N,sizeof(int),compar);
		qsort(candidates[1],N,sizeof(int),compar);
		for(i=0;i<N;i++) if(candidates[0][i]!=candidates[1][i]) break;
		if(i<N) puts("NO");
		else puts("YES");
	}
	return 0;
}
