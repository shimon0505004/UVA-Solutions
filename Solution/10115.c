#include<stdio.h>
#include<string.h>
typedef struct RULE{
	char target[400];
	char des[400];
}Rule;
int main(){
	int n,i;
	Rule r[15];
	char text[400],*ptr,temp[400];
	while(scanf("%d ",&n),n){
		for(i=0;i<n;i++){
			fgets(r[i].target,400,stdin);
			r[i].target[strlen(r[i].target)-1]=0;
			fgets(r[i].des,400,stdin);
			r[i].des[strlen(r[i].des)-1]=0;
		}
		fgets(text,400,stdin);
		for(i=0;i<n;i++)
			for(ptr=text;(ptr=strstr(ptr,r[i].target))!=NULL;strcpy(text,temp))
				sprintf(temp,"%.*s%s%s",ptr-text,text,r[i].des,ptr+strlen(r[i].target));
		printf(text);
	}
	return 0;
}
