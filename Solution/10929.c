#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[1005];
	int odd,even,len,i;
	while(scanf("%s",input)==1){
		if(strlen(input)==1&&*input=='0') break;
		odd=even=0;
		len=strlen(input);
		for(i=0;i<len;i++){
			if(i%2)
				odd+=input[i]-'0';
			else
				even+=input[i]-'0';
		}
		if(abs(odd-even)%11==0)
			printf("%s is a multiple of 11.\n",input);
		else
			printf("%s is not a multiple of 11.\n",input);
	}
	return 0;
}
