#include<stdio.h>
#include<string.h>
int main()
{
	char word[50000]={0},temp[50000]={0},*aeiou="AEIOUaeiou";
	char *alphebat="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	
	for(i=0;(word[i]=getchar())!=EOF;i++){
		if(strchr(alphebat,word[i])==NULL){
			strncpy(temp,word,i);
			if(strchr(aeiou,temp[0])!=NULL)
				printf("%s%s%c",temp,(!strcmp(temp,"")?"":"ay"),word[i]);
			else
				printf("%s%c%s%c",temp+1,temp[0],(!strcmp(temp,"")?"":"ay"),word[i]);	
			i=-1;
			memset(word,0,sizeof(word));
	                memset(temp,0,sizeof(temp));
		}
	}
	strncpy(temp,word,i);
	if(strchr(aeiou,temp[0])!=NULL)
		printf("%s%s",temp,(!strcmp(temp,"")?"":"ay"));
	else
		printf("%s%c%s",temp+1,temp[0],(!strcmp(temp,"")?"":"ay"));
	return 0;
}
