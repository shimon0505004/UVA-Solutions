#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main()
{
	int cases;
	int i,nrelatives;
	int doornum[505],median;
	int distance;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&nrelatives);
		for(i=0;i<nrelatives;i++)
			scanf("%d",&doornum[i]);
		qsort(doornum,nrelatives,sizeof(int),compar);
		median=doornum[nrelatives/2];
		distance=0;
		for(i=0;i<nrelatives;i++)
			distance+=abs(doornum[i]-median);
		printf("%d\n",distance);
	}
	return 0;
}
