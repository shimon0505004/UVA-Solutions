#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define PLUS 1
#define PREFIX 2
#define MINUS 4
#define POSTFIX 8
int main(){
	int v[26];
	char u_opr[26];
	char sign[26];
	int i,value[26],result;
	char expr[150],*ptr;
	for(i=0;i<26;i++) v[i]=i;
	while(fgets(expr+1,150,stdin)!=NULL){
		printf("Expression: %s",expr+1);
		memset(u_opr,0,sizeof(u_opr));
		memset(value,0,sizeof(value));
		memset(sign,0,sizeof(sign));
		expr[0]='\0';
		for(i=1,ptr=expr+1;*ptr!='\n';i++,ptr++){
			while(*ptr==' ') ptr++;
			expr[i]=*ptr;
		}
		expr[i]='\0';
		for(i=0;i<26;i++){
			if((ptr=strchr(expr+1,i+'a'))!=NULL){
				value[i]=i+1;
				if(*(ptr-2)=='+'&&*(ptr-1)=='+'){
					u_opr[i]=PLUS|PREFIX;
					if(*(ptr-3)=='-') sign[i]=MINUS;
				}else if(*(ptr-2)=='-'&&*(ptr-1)=='-'){
					u_opr[i]=MINUS|PREFIX;
					if(*(ptr-3)=='-') sign[i]=MINUS;
				}else if(*(ptr+2)=='+'&&*(ptr+1)=='+'){
					u_opr[i]=PLUS|POSTFIX;
					if(*(ptr-1)=='-') sign[i]=MINUS;
				}else if(*(ptr+2)=='-'&&*(ptr+1)=='-'){
					u_opr[i]=MINUS|POSTFIX;
					if(*(ptr-1)=='-') sign[i]=MINUS;
				}else{
					if(*(ptr-1)=='-') sign[i]=MINUS;
				}
			}
		}
		result=0;
		for(i=0;i<26;i++){
			if(u_opr[i]&PREFIX){
				if(u_opr[i]&MINUS) value[i]--;
				else value[i]++;
			}
			result+=(sign[i]==MINUS?-1:1)*value[i];
		}
		printf("    value = %d\n",result);
		for(i=0;i<26;i++){
			if(u_opr[i]&POSTFIX){
				if(u_opr[i]&MINUS) value[i]--;
				else value[i]++;
			}
			if(u_opr[i]||value[i])
				printf("    %c = %d\n",'a'+i,value[i]);
		}
	}
	return 0;
}
