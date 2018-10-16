#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct DICTIONARY{
	char word[10];
	char sort[10];
}Dict;
int compar1(const void *a,const void *b){
	return *((char *)a)-*((char *)b);
}
int compar2(const void *a,const void *b){
	return strcmp(((Dict *)a)->word,((Dict *)b)->word);
}
int main(){
	Dict w[105];
	char query[10],flag;
	int n,i;
	for(n=0;scanf("%s",w[n].word);n++){
		if(strcmp(w[n].word,"XXXXXX")==0) break;
		strcpy(w[n].sort,w[n].word);
		qsort(w[n].sort,strlen(w[n].sort),sizeof(char),compar1);
	}
	qsort(w,n,sizeof(Dict),compar2);
	while(scanf("%s",query)){
		if(strcmp(query,"XXXXXX")==0) break;
		qsort(query,strlen(query),sizeof(char),compar1);
		flag=0;
		for(i=0;i<n;i++)
			if(strcmp(query,w[i].sort)==0) puts(w[i].word),flag=1;
		if(flag==0) puts("NOT A VALID WORD");
		puts("******");
	}
	return 0;
}
