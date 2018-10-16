#include<stdio.h>
#include<string.h>
int main(){
	int cases,i,len;
	char map[128];
	char input[80],temp[80];
	scanf("%d ",&cases);
	while(cases--){
		for(i=0;i<128;i++) map[i]=i;
		fgets(input,80,stdin);
		fgets(temp,80,stdin);
		printf(temp),printf(input);
		len=strlen(input);
		for(i=0;i<len;i++) map[input[i]]=temp[i];
		while(fgets(input,80,stdin)!=NULL){
			if(*input=='\n') break;
			len=strlen(input);
			for(i=0;i<len;i++) putchar(map[input[i]]);
		}
		if(cases) puts("");
	}
	return 0;
}
