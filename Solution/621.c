#include<stdio.h>
int main()
{
	int cases,i;
	char s[1000];
	char positive[3][3]={"1","4","78"};
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",s);
		for(i=0;i<3;i++)
			if(!strcmp(s,positive[i])){
				puts("+");
				break;
			}
		if(i==3){
			if(!strcmp(s+strlen(s)-2,"35")){
				puts("-");
			}else if(*s=='9'&&*(s+strlen(s)-1)=='4'){
				puts("*");
			}else 
				puts("?");
		}
	}
	return 0;
}
