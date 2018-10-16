#include<stdio.h>
#include<ctype.h>
int main()
{
	const char *code="01230120022455012623010202";
	char input[30],comp,temp;
	int i;
	while(fgets(input,30,stdin)!=NULL){
		comp=0;
		for(i=0;isalpha(input[i]);i++){
			temp=code[input[i]-'A'];
			if(temp!=comp){
				comp=temp;
				if(temp!='0')
					putchar(temp);
			}
		}
		puts("");
	}
	return 0;
}
