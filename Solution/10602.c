#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char word[105][105];
int compar(const void *a,const void *b){
	char *s1=(char *)a,*s2=(char *)b;
	int comm1,comm2;
	for(comm1=0;s1[comm1]==word[0][comm1]&&s1[comm1]!='\0';comm1++);
	for(comm2=0;s2[comm2]==word[0][comm2]&&s2[comm2]!='\0';comm2++);
	if(comm1!=comm2) return comm2-comm1;
	return strcmp(s1,s2);
}
int main(){
	int cases,n_word,n_press;
	int i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n_word);
		for(i=0;i<n_word;i++) scanf("%s",word[i]);
		qsort(word+1,n_word-1,sizeof(char[105]),compar);
		n_press=strlen(word[0]);
		for(i=1;i<n_word;i++){
			int com;
			for(com=0;word[i][com]==word[i-1][com]&&word[i][com]!='\0';com++);
			n_press+=strlen(word[i])-com;
		}
		printf("%d\n",n_press);
		for(i=0;i<n_word;i++) puts(word[i]);
	}
	return 0;
}
