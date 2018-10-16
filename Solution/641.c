#include<stdio.h>
#include<string.h>
int main(){
	int k,i,len;
	const char map[29]="_abcdefghijklmnopqrstuvwxyz.";
	char cipher[100];
	char decode[100];
	while(scanf("%d%s",&k,cipher),k){
		memset(decode,0,sizeof(decode));
		len=strlen(cipher);
		for(i=0;i<len;i++)
			decode[k*i%len]=map[(strchr(map,cipher[i])-map+i)%28];
		puts(decode);
	}
	return 0;
}
