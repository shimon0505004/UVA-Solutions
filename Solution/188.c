#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
int convert(char *s){
	int len=strlen(s),i,result=0;
	for(i=0;i<len;i++)
		result=(result<<5)+s[i]-'a'+1;
	return result;
}
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	char input[100],*ptr;
	int word[15],i,j,count,C;
	int occupy[15],modulo,conflict;
	while(fgets(input,100,stdin)!=NULL){
		printf(input);
		input[strlen(input)-1]=0;
		for(ptr=strtok(input," "),count=0;ptr!=NULL;ptr=strtok(NULL," "),count++)
			word[count]=convert(ptr);
		qsort(word,count,sizeof(int),compar);
		memset(occupy,255,sizeof(occupy));
		for(i=0,C=word[0];i<count;){
			modulo=C/word[i]%count;
			conflict=occupy[modulo];
			if(conflict==-1) occupy[modulo]=i,i++;
			else{
				C=MIN((C/word[i]+1)*word[i],(C/word[conflict]+1)*word[conflict]);
				i=0,memset(occupy,255,sizeof(occupy));
			}
		}
		printf("%d\n",C);
		puts("");
	}
	return 0;
}
