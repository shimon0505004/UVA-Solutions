#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct atcg{
	char Seq[55];
	int swaps;
};
int compar(const void *a,const void *b){
	return ((struct atcg*)a)->swaps-((struct atcg*)b)->swaps;
}
int count(char DNA[],int len){
	int i,ATCG[4]={0},result=0;
	for(i=0;i<len;i++){
		if(DNA[i]=='A') ATCG[0]++,result+=ATCG[1]+ATCG[2]+ATCG[3];
		else if(DNA[i]=='C') ATCG[1]++,result+=ATCG[2]+ATCG[3];
		else if(DNA[i]=='G') ATCG[2]++,result+=ATCG[3];
		else if(DNA[i]=='T') ATCG[3]++;
	}
	return result;
}
int main()
{
	int cases;
	int n,m,i;
	struct atcg ATCG[105];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%s",ATCG[i].Seq);
			ATCG[i].swaps=count(ATCG[i].Seq,n);
		}
		qsort(ATCG,m,sizeof(struct atcg),compar);
		for(i=0;i<m;i++)
			puts(ATCG[i].Seq);
		if(cases) puts("");
	}
}
