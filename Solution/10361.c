#include<stdio.h>
#include<string.h>
int main()
{
	int cases,i;
	char l[110],*Ptr,*tempPtr;
	char s[5][110];
	scanf("%d ",&cases);
	while(cases--){
		fgets(l,110,stdin);
		tempPtr=l;
		memset(s,0,sizeof(s));
		for(i=0;i<4;i++){
			Ptr=strpbrk(tempPtr,"<>");
			strncpy(s[i],tempPtr,Ptr-tempPtr);
			tempPtr=Ptr+1;
			printf("%s",s[i]);
		}
		strcpy(s[4],tempPtr);
		printf("%s",s[4]);
		fgets(l,110,stdin);
		printf("%.*s",strstr(l,"...")-l,l);
		printf("%s%s%s%s",s[3],s[2],s[1],s[4]);
	}
	return 0;
}
