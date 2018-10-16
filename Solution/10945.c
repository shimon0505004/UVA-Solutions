#include<stdio.h>
#include<ctype.h>
int main(){
	char input[100],a;
	int i,len;
	for(;;){
		for(i=0;(a=getchar())!='\n';) if(isalpha(a)) input[i++]=a;
		input[len=i]=0;
		if(strncmp(input,"DONE",4)==0) break;
		for(i=0;i<len/2;i++)
			if(tolower(input[i])!=tolower(input[len-i-1])) break;
		if(i<len/2) puts("Uh oh..");
		else puts("You won't be eaten!");
	}
	return 0;
}
