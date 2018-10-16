#include<stdio.h>
#include<string.h>
void printMTM(char input[]){
	if(*input=='2'){
		if(*(input+1)==0) printf(input);
		else printMTM(input+1);
	}else if(*input=='3'){
		int n_of_3=strspn(input,"3");
		if(input[n_of_3+1]!=0&&input[n_of_3]=='2'){
			printMTM(input+1),putchar('2'),printMTM(input+1);
		}else printf(input);
	}else printf(input);
}
int main(){
	char input[35];
	int len;
	while(fgets(input,35,stdin),strcmp(input,"0\n")){
		if(strchr(input,'0')!=NULL){
			puts("NOT ACCEPTABLE");
			continue;
		}
		len=strlen(input);
		input[--len]=0;
		if(*input!='3'&&*input!='2'){
			puts("NOT ACCEPTABLE");
			continue;
		}
		if(*input=='3'){
			int n_of_3=strspn(input,"3");
			if(n_of_3>=len-1||input[n_of_3]!='2'){
				puts("NOT ACCEPTABLE");
				continue;
			}
		}
		printMTM(input);
		puts("");
	}
	return 0;
}
