#include<stdio.h>
#include<string.h>
int ispalin(char s[],int len){
	int i;
	for(i=0;i<len/2;i++)
		if(s[i]!=s[len-i-1]) return 0;
	return 1;
}
int main()
{
	char input[90];
	int i,j,len,result;
	char dup[85];
	while(scanf("%s",input)==1){
		len=strlen(input);
		result=0;
		for(i=1;i<=len;i++){
			for(j=len-i;j>=0;j--){
				strncpy(dup,input+j,i);
				dup[i]=0;
				if(strstr(input+j+1,dup)!=NULL) continue;
				result+=ispalin(input+j,i);
			}
		}
		printf("The string '%s' contains %d palindromes.\n",input,result);
	}
	return 0;
}
