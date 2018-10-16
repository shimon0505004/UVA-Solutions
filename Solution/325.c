#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char input[5000],*ptr,*dotPtr;
	int len;
	while(fgets(input,5000,stdin),*input!='*'){
		len=strlen(input);
		ptr=input+len-1;
		while(*--ptr==' ');
		ptr[1]=0,ptr=input-1;
		while(*++ptr==' ');
		printf("%s is ",ptr);
		if(*ptr=='+'||*ptr=='-') ptr++;
		if(!isdigit(*ptr)){
			puts("illegal.");
			continue;
		}
		while(isdigit(*++ptr));
		if(*ptr=='.'){
			if(!isdigit(ptr[1])){
				puts("illegal.");
				continue;
			}
			while(isdigit(*++ptr));
			if(*ptr==0){
				puts("legal.");
				continue;
			}
		}
		if(*ptr=='e'||*ptr=='E'){
			if(ptr[1]=='+'||ptr[1]=='-') ptr++;
			if(!isdigit(ptr[1])){
				puts("illegal.");
				continue;
			}
			ptr++;
		}else{
			puts("illegal.");
			continue;
		}
		while(isdigit(*++ptr));
		if(*ptr==0) puts("legal.");
		else puts("illegal.");
	}
	return 0;
}
