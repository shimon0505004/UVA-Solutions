#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int offset;
int compar(const void *a,const void *b){
	char *s1=*((char **)a),*s2=*((char **)b);
	return strcmp(s1+offset,s2+offset);
}
int main(){
	char line[305];
	int n,len,i;
	char *matrix[305],start=0;
	for(i=0;i<305;i++) matrix[i]=(char *)malloc(sizeof(char[305]));
	while(scanf("%s%d",line,&n),n){
		if(start) puts("");
		else start=1;
		len=strlen(line);
		for(i=0;i<len;i++) matrix[i][len]=0;
		for(offset=len-1;offset>=0;offset--){
			for(i=0;i<len;i++) matrix[i][offset]=line[i];
			qsort(matrix,len,sizeof(char *),compar);
		}
		puts(matrix[n-1]);
	}
	return 0;
}
