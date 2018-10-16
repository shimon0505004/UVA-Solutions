#include<stdio.h>
#include<string.h>
#include<ctype.h>
int flag;
int countlen(char *s){
	int result=0;
	for(;*s;s++) if(isalpha(*s)) result++;
	if(flag){
		result+=flag;
		flag=0;
		return result;
	}
	if(*(s-1)=='-'){
		flag=result;
		return 0;
	}
	return result;
}
int main()
{
	char input[85],*ptr;
	int length[31],i,len,max;
	flag=0;
	for(;;){
		memset(length,0,sizeof(length));
		max=0;
		while(fgets(input,85,stdin)!=NULL){
			input[strlen(input)-1]=0;
			if(*input=='#') break;
			for(ptr=strtok(input," ?!,.");ptr!=NULL;ptr=strtok(NULL," ?!,.")){
				len=countlen(ptr);
				length[len]++;
				if(max<len) max=len;
			}
		}
		for(i=1;i<=max;i++)
			if(length[i])
				printf("%d %d\n",i,length[i]);
		if(feof(stdin)) break;
		puts("");
	}
	return 0;
}
