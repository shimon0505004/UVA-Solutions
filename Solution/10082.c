#include<stdio.h>
int main()
{
	char keyboard[65]={0},input[1000];
	int i,j,n,k;
	strcpy(keyboard,"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
	while(gets(input)!=NULL){
		n=strlen(input);
		for(k=0;k<n;k++)
			for(i=0;i<65;i++)
				if(input[k]==' '){
					printf(" ");
					break;
				}
				else if(input[k]==keyboard[i])
					printf("%c",keyboard[i-1]);
		printf("\n");
		
	}
	return 0;
}
