#include<stdio.h>
#include<string.h>
char ispalinwords(char words[]){
	int i,len=strlen(words),palins=0,count=0;
	char palin[2][5]={0};
	for(i=1;i<len-1;i++){
		if(words[i-1]==words[i+1]&&strncmp(palin[0],words+i-1,3)){
			if(count) return 1;
			strncpy(palin[count++],words+i-1,3);
		}else if(words[i-1]==words[i+2]&&words[i]==words[i+1]&&strncmp(palin[0],words+i-1,3)){
			if(count) return 1;
			strncpy(palin[count++],words+i-1,3);
		}
	}
	return 0;
}
int main(){
	char words[260];
	while(scanf("%s",words)==1)
		if(ispalinwords(words)) puts(words);
	return 0;
}
