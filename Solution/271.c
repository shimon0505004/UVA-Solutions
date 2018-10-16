#include<stdio.h>
char *Syntax;
char CheckSyntax()
{
	if(*Syntax=='\0') return 0;
	if(*Syntax>='p'&&*Syntax<='z'){
		Syntax++;
		return 1;
	}
	else if(*Syntax=='N'){
		Syntax++;
		return CheckSyntax();
	}
	else if((*Syntax=='C')||(*Syntax=='D')||(*Syntax=='E')||(*Syntax=='I')){
		Syntax++;
		if(CheckSyntax()&&CheckSyntax()) return 1;
		else return 0;
	}
}
int main()
{
	char Hedonian[260];
	while(scanf("%s",Hedonian)==1){
		Syntax=Hedonian;
		if(CheckSyntax()&&!*Syntax)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
