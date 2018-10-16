#include<stdio.h>
#include<string.h>
void reverse(char num[])
{
	char hold;
	int i;
	for(i=0;i<strlen(num)/2;i++){
		hold=num[i];
		num[i]=num[strlen(num)-1-i];
		num[strlen(num)-1-i]=hold;
	}
}
int main()
{
	char word[50000]={0},temp[50000]={0};
	int i,j;
	
	for(i=0;(word[i]=getchar())!=EOF;i++){
		if(word[i]==' ' || word[i]=='\n'){
			strncpy(temp,word,i);
			reverse(temp);
			printf("%s%c",temp,word[i]);
			i=-1;
			memset(word,0,sizeof(word));
	                memset(temp,0,sizeof(temp));
		}
	}
	strncpy(temp,word,i);
	reverse(temp);
	printf("%s",temp);
	return 0;
}

