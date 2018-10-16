#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n,m,check,cases=0,len,i,j,charsQ,charsS;
	char ques[100][200],temp[5];
	char submit[100][200];
	char judgedigit[20000];
	char submitdigit[20000];
	while(scanf("%d",&n)==1&&n){
		fgets(temp,10,stdin);
		if(!n) break;
		memset(ques,0,sizeof(ques));
		for(i=0;i<n;i++){
			fgets(ques[i],190,stdin);
			ques[i][strlen(ques[i])-1]=0;
		}
		scanf("%d",&m);
		fgets(temp,10,stdin);
		memset(submit,0,sizeof(submit));
		for(i=0;i<m;i++){
			fgets(submit[i],190,stdin);
			submit[i][strlen(submit[i])-1]=0;
		}
		printf("Run #%d: ",++cases);
		check=0;
		if(n==m){
			for(i=0;i<m;i++)
				if(strcmp(ques[i],submit[i])){
					check=1;
					break;
				}
			if(!check){
				printf("Accepted\n");
				continue;
			}
		}
		memset(judgedigit,0,sizeof(judgedigit));
		charsQ=0;
		for(i=0;i<n;i++){
			len=strlen(ques[i]);
			for(j=0;j<len;j++)
				if(isdigit(ques[i][j]))
					judgedigit[charsQ++]=ques[i][j];
		}
		memset(submitdigit,0,sizeof(submitdigit));
		charsS=0;
		for(i=0;i<m;i++){
			len=strlen(submit[i]);
			for(j=0;j<len;j++)
				if(isdigit(submit[i][j]))
					submitdigit[charsS++]=submit[i][j];
		}
		if(!strcmp(submitdigit,judgedigit))
			printf("Presentation Error\n");
		else
			printf("Wrong Answer\n");
	}
	return 0;
}
