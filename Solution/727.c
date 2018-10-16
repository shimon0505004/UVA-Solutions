#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 51
char num[MAX_SIZE];
int n_num;
int num_is_empty(){
	return n_num==0;
}
void push(char c){
	num[n_num++]=c;
}
char pop(){
	return num[--n_num];
}
int main()
{
	int cases,i;
	char temp[3];
	while(scanf("%d ",&cases)==1){
		for(i=0;i<cases;i++){
			if(i) puts("");
			n_num=0;
			for(;;){
				fgets(temp,3,stdin);
				if(*temp=='\n'||feof(stdin)) break;
				if(isdigit(*temp)){
					putchar(*temp);
					continue;
				}else if(*temp=='*'||*temp=='/')
					while(num[n_num-1]=='/'||num[n_num-1]=='*') putchar(pop());
				else if(*temp=='+'||*temp=='-')
					while(num[n_num-1]!='('&&!num_is_empty()) putchar(pop());
				else if(*temp==')'){
					char c;
					for(;;){
						c=pop();
						if(c=='(') break;
						putchar(c);
					}
					continue;
				}
				push(*temp);
			}
			while(!num_is_empty())
				putchar(pop());
			puts("");
		}
	}
	return 0;
}
