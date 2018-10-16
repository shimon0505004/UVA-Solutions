#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char line[65],buffer[65],isbuffer,*ptr;
	int len,i;
	isbuffer=0;
	while(fgets(line,65,stdin),*line!='#'||strlen(line)!=2){
		ptr=line;
		ptr[strlen(ptr)-1]=0;
		if(isbuffer){
			isbuffer=0;
			printf(buffer);
			ptr+=printf("%.*s\n",strchr(ptr,' ')-ptr,ptr)-1;
		}
		if(ptr[strlen(ptr)-1]=='-'){
			ptr[strlen(ptr)-1]=0;
			sprintf(buffer,"%s",strrchr(ptr,' ')+1);
			*(strrchr(ptr,' ')+1)=0;
			isbuffer=1;
		}
		len=strlen(ptr);
		for(i=0;i<len;i++) if(isspace(ptr[i])||isalpha(ptr[i])) putchar(ptr[i]);
		puts("");
	}
	return 0;
}
