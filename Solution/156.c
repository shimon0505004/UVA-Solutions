#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<ctype.h>
struct DICT{
	char word[25];
	char orig[25];
};
int compar(const void *a,const void *b){
	return tolower(*((char *)a))-tolower(*((char *)b));
}
int compar2(const void *a,const void *b){
	struct DICT *w1=(struct DICT *)a,*w2=(struct DICT *)b;
	return strcasecmp(w1->orig,w2->orig);
}
int compar3(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
int main(){
	struct DICT w[1000];
	char out[1000][25];
	int i,n,count=0;
	for(i=0;;i++){
		scanf("%s",w[i].word);
		strcpy(w[i].orig,w[i].word);
		if(*(w[i].word)=='#') break;
	}
	n=i;
	for(i=0;i<n;i++)
		qsort(w[i].orig,strlen(w[i].orig),1,compar);
	qsort(w,n,sizeof(struct DICT),compar2);
	if(strcasecmp(w[0].orig,w[1].orig)) strcpy(out[count++],w[0].word);
	for(i=1;i<n-1;i++){
		if(strcasecmp(w[i].orig,w[i-1].orig)&&strcasecmp(w[i].orig,w[i+1].orig))
			strcpy(out[count++],w[i].word);
	}
	if(strcasecmp(w[n-2].orig,w[n-1].orig)) strcpy(out[count++],w[n-1].word);
	qsort(out,count,25,compar3);
	for(i=0;i<count;i++)
		puts(out[i]);
}
