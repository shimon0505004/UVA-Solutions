#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compar(const void *a,const void *b){
	char *s1=(char *)a,*s2=(char *)b;
	char temp1[200]={0},temp2[200]={0};
	strcat(temp1,s2);
	strcat(temp1,s1);
	strcat(temp2,s1);
	strcat(temp2,s2);
	return strcmp(temp1,temp2);
}
int main(){
	int n,i;
	char gameN[55][200];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++) scanf("%s",gameN[i]);
		qsort(gameN,n,sizeof(char[200]),compar);
		for(i=0;i<n;i++) printf("%s",gameN[i]);
		puts("");
	}
	return 0;
}
