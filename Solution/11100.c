#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int N,i,j;
	char start=0;
	int bag[10005],max,cur;
	while(scanf("%d",&N),N){
		if(start) puts("");
		else start=1;
		for(i=0;i<N;i++) scanf("%d",&bag[i]);
		qsort(bag,N,sizeof(int),compar);
		cur=max=1;
		for(i=1;i<N;i++){
			if(bag[i]==bag[i-1]) cur++;
			else cur=1;
			max=MAX(max,cur);
		}
		printf("%d\n",max);
		for(i=0;i<max;i++){
			printf("%d",bag[i]);
			for(j=i+max;j<N;j+=max)
				printf(" %d",bag[j]);
			puts("");
		}
	}
	return 0;
}
