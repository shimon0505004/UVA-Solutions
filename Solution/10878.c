#include<stdio.h>
int main()
{
	char tape[15];
	int i;
	char out;
	fgets(tape,15,stdin);
	while(fgets(tape,15,stdin)!=NULL){
		if(!strcmp(tape,"___________\n")) break;
		out=0;
		for(i=2;i<=9;i++){
			if(tape[i]=='.') continue;
			out<<=1;
			out+=(tape[i]=='o'?1:0);
		}
		putchar(out);
	}
	return 0;
}
