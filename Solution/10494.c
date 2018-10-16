#include<stdio.h>
#include<string.h>
int main()
{
	char divide[577],operator;
	long long div,result,remainder;
	int len,i;
	while(scanf("%s %c%lld",divide,&operator,&div)==3){
		result=0;
		len=strlen(divide);
		if(operator=='%'){
			for(i=0;i<len;i++)
				result=(result*10+divide[i]-'0')%div;
			printf("%lld\n",result);
		}
		else{
			remainder=0;
			for(i=0;i<len;i++){
				remainder=remainder*10+divide[i]-'0';
				divide[i]=remainder/div+'0';
				remainder%=div;
			}
			if(strlen(divide+strspn(divide,"0")))
				puts(divide+strspn(divide,"0"));
			else
				puts("0");
		}
	}
	return 0;
}
