#include<stdio.h>
#include<string.h>
#define MAX_SIZE 130
char stack[MAX_SIZE];
int n_stack;
void push(char k)
{
	stack[n_stack++] = k;
}
char pop()
{
	return stack[--n_stack];
}
int is_empty()
{
	return !n_stack;
}
char end(char type)
{
	switch(type){
		case '(':
			return ')';
		case '[':
			return ']';
	}
}
int main()
{
	int cases,i,len;
	char input[130],a;
	scanf("%d ",&cases);
	while(cases--){
		fgets(input,130,stdin);
		len=strlen(input);
		input[--len]=0;
		if(len%2)
			puts("No");
		else if(len){
			n_stack=0;
			for(i=0;input[i];i++)
				if(input[i]=='('||input[i]=='[')
					push(input[i]);
				else if(input[i]==')'||input[i]==']')
					if(is_empty()||input[i]!=end(pop()))
						break;
			if(input[i]||!is_empty())
				puts("No");
			else
				puts("Yes");
		}
		else
			puts("Yes");
	}
	return 0;
}
