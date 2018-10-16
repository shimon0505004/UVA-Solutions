#include<stdio.h>
#include<string.h>
int main()
{
	char s[17],t[90001],*strPtr;
	int nofs,i;
	while(scanf("%s%s",s,t)!=EOF){
		nofs=strlen(s);
		strPtr=t;
		for(i=0;i<nofs;i++,strPtr++){
			strPtr=strchr(strPtr,s[i]);
			if(strPtr==NULL){
				printf("No\n");
				break;
			}
		}
		if(i==nofs)
			printf("Yes\n");
	}
	return 0;
}
