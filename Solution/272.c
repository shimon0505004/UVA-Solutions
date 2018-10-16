#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char sentence[1000],*senPtr;
	int i,times=0;
	while(gets(sentence)){
		for(i=0;i<strlen(sentence);i++){
			if(sentence[i]=='"'){
				senPtr=sentence+i;
				memmove(senPtr+1,senPtr,strlen(sentence));
				if(times==0)
					sentence[i]=sentence[i+1]='`';
				else
					sentence[i]=sentence[i+1]='\'';
				times=(times+1)%2;
			}
		}
		printf("%s\n",sentence);
		memset(sentence,0,sizeof(sentence));
	}
	return 0;
}
