#include<stdio.h>
#include<string.h>
int main()
{
	char skew[50];
	int len,i,result;
	while(scanf("%s",&skew)&&*skew!='0'){
		len=strlen(skew);
		for(result=0,i=0;i<len;i++)
			result+=(skew[i]-'0')*((1<<(len-i))-1);
		printf("%d\n",result);
	}
	return 0;
}
