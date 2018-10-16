#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
char cmp(char f1[],char f2[],int T){
	int i;
	for(i=0;i<T;i++)
		if(f1[i]!=f2[i]) return 1;
	return 0;
}
int main(){
	char forest[105][105],input[10];
	int cases,P,T,i,j,m,t,view;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d ",&P,&T);
		if(P==0||T==0){
			puts("0");
			if(cases) puts("");
			continue;
		}
		memset(forest,2,sizeof(forest));
		for(i=0;i<P;i++)
			forest[i][T]=0;
		while(fgets(input,10,stdin)!=NULL&&*input!='\n'){
			sscanf(input,"%d%d",&m,&t);
			forest[m-1][t-1]=1;
		}
		view=1;
		qsort(forest,P,sizeof(char[105]),compar);
		for(i=1;i<P;i++)
			if(cmp(forest[i],forest[i-1],T)) view++;
		printf("%d\n",view);
		if(cases) puts("");
	}
	return 0;
}
