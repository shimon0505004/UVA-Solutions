#include<stdio.h>
#include<string.h>
int result[210],len;
void multiply(char *n)
{
	int i,j;
	memset(result,0,sizeof(result));
	for(i=0;i<len;i++)
		for(j=0;j<len-1;j++)
			result[i+j+1]+=(n[i]-'0')*(n[j]-'0');
	for(i=0;i<len;i++)
		result[i+len]+=(n[i]-'0')*(n[len-1]-'0'-1);
	result[2*len-1]+=2;
	for(i=2*len-2;i>=0;i--){
		if(result[i+1]<0){
			result[i+1]+=10;
			result[i]--;
		}
		result[i]+=result[i+1]/10;
		result[i+1]%=10;
	}
}
int main()
{
	char input[105];
	int i,j;
	while(scanf("%s",input)==1){
		if(*input=='0') puts("1");
		else{
			len=strlen(input);
			multiply(input);
			for(i=0;!result[i];i++);
			for(j=i;j<2*len;j++)
				printf("%d",result[j]);
			puts("");
		}
	}
	return 0;
}
