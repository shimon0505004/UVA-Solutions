#include<stdio.h>
#include<string.h>
int main()
{
	int test=131071;
	char input[10010];
	int result,len,i;
	while(1){
		result=0;
		if(scanf("%s",input)!=1) break;
		len=strlen(input);
		if(input[len-1]=='#'){
			for(i=0;i<len-1;i++){
				result<<=1;
				result+=(input[i]=='1'?1:0);
				result%=test;
			}
			if(result)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}
