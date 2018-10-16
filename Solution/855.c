#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int cases,S,A,F;
	int i;
	int avenue[50005],street[50005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&S,&A,&F);
		for(i=0;i<F;i++) scanf("%d%d",&street[i],&avenue[i]);
		qsort(street,F,sizeof(int),compar);
		qsort(avenue,F,sizeof(int),compar);
		printf("(Street: %d, Avenue: %d)\n",street[(F-1)/2],avenue[(F-1)/2]);
	}
	return 0;
}
