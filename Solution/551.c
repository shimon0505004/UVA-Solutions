#include<stdio.h>
#include<string.h>
char stack[3005];
int n_stack;
void push(char c){
	stack[n_stack++]=c;
}
char pop(){
	return stack[--n_stack];
}
char is_empty(){
	return n_stack==0;
}
int main(){
	char line[3005],*ptr;
	char input[3005],*ptr2;
	char open[128];
	open[')']='(',open[']']='[',open['}']='{',open['>']='<',open[2]=1;
	while(fgets(line,3005,stdin)!=NULL){
		for(ptr=line,ptr2=input;*ptr!='\n';ptr++){
			if(*ptr=='('&&*(ptr+1)=='*')
				*ptr2++=1,ptr++;
			else if(*ptr=='*'&&*(ptr+1)==')')
				*ptr2++=2,ptr++;
			else *ptr2++=*ptr;
		}
		*ptr2=0;
		n_stack=0;
		for(ptr=input;*ptr!=0;ptr++){
			if(*ptr=='('||*ptr=='['||*ptr=='{'||*ptr=='<'||*ptr==1)
				push(*ptr);
			else if(*ptr==')'||*ptr==']'||*ptr=='}'||*ptr=='>'||*ptr==2){
				if(is_empty()||pop()!=open[*ptr]){
					printf("NO %d\n",ptr-input+1);
					break;
				}
			}
		}
		if(*ptr==0){
			if(is_empty()) puts("YES");
			else printf("NO %d\n",ptr-input+1);
		}
	}
	return 0;
}
