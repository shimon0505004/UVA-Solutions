#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char*);
int main()
{
	int i,n,times;
	char inpnum[100]="",temp[100]="";
	unsigned long result=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",inpnum);
		times=0;
		strcpy(temp,inpnum);
		reverse(temp);
		do{
			times++;
			result=atol(inpnum)+atol(temp);
			sprintf(inpnum,"%lu",result);
			strcpy(temp,inpnum);
			reverse(temp);
		}while(strcmp(temp,inpnum)!=0);
		printf("%d %lu\n",times,result);
	}
	return 0;
}
void reverse(char num[])
{
	char hold;
	int i;
	for(i=0;i<strlen(num)/2;i++){
		hold=num[i];
		num[i]=num[strlen(num)-1-i];
		num[strlen(num)-1-i]=hold;
	}
}

