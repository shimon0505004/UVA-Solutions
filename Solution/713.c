#include<stdio.h>
#include<string.h>
void add(char*,char*,char*);
void reverse(char*);
int main()
{
	int n,i,j,len;
	char num1[210],num2[210],result[210];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%s",num1,num2);
		reverse(num1);
		reverse(num2);
		add(num1,num2,result);
		reverse(result);
		printf("%s\n",result+strspn(result,"0"));
	}
	return 0;
}
void add(char*num1,char*num2,char*result)
{
	int len1,len2,len,i;
	for(i=0;i<200;i++)
		result[i]=0;
	len1=strlen(num1);
	len2=strlen(num2);
	len=(len1>len2?len1:len2);
	for(i=0;i<len;i++)
		result[len-i]=((len1-i-1)<0?0:num1[len1-i-1]-'0')+((len2-i-1)<0?0:num2[len2-i-1]-'0');
	for(i=len;i>0;i--){
		if(result[i]>=10){
			result[i]%=10;
			result[i-1]++;
		}
	}
	for(i=0;i<len+1;i++)
		result[i]+='0';
	sprintf(result,result+strspn(result,"0"));
	return;
}
void reverse(char*num)
{
	char hold;
	int i;
	for(i=0;i<strlen(num)/2;i++){
		hold=num[i];
		num[i]=num[strlen(num)-1-i];
		num[strlen(num)-1-i]=hold;
	}
}
