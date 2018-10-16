#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 15
int compar(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
int main(){
	char word[120005][MAXLENGTH],temp[MAXLENGTH];
	int count,i,j,len;
	for(count=0;scanf("%s",word[count])==1;count++);
	for(i=0;i<count;i++){
		len=strlen(word[i]);
		memset(temp,0,sizeof(temp));
		for(j=0;j<len-1;j++){
			temp[j]=word[i][j];
			if(bsearch(temp,word,count,sizeof(char[MAXLENGTH]),compar)!=NULL)
				if(bsearch(word[i]+j+1,word,count,sizeof(char[MAXLENGTH]),compar)!=NULL){
					puts(word[i]);
					break;
				}
		}
	}
	return 0;
}
