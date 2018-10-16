#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char keyboard[65]={0},input[1000],*find;
	int i,j,n,k;
	strcpy(keyboard,"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./");
	fgets(input,1000,stdin);
	n=strlen(input);
	for(k=0;k<n;k++){
		find=strchr(keyboard,tolower(input[k]));
		if(find==NULL)
			printf("%c",input[k]);
		else
			printf("%c",keyboard[find-keyboard-2]);
	}
	return 0;
}
