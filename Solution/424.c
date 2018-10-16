#include<stdio.h>
#include<string.h>
void reverse(char *string)
{
	int i,len=strlen(string);
	char temp;
	for(i=0;i<len/2;i++){
		temp=string[i];
		string[i]=string[len-i-1];
		string[len-i-1]=temp;
	}
}
int main()
{
	char num[105][105],strresult[105];
	int result[105];
	int i,j,n,len,maxlen;
	memset(num,0,sizeof(num));
	for(i=0;;i++){
		scanf("%s",num[i]);
		if(num[i][0]=='0'){
			n=i;
			break;
		}
	}
	memset(result,0,sizeof(result));
	for(i=1,maxlen=strlen(num[0]);i<n;i++)
		maxlen=(strlen(num[i])>maxlen?strlen(num[i]):maxlen);
	for(i=0;i<105;i++){
		for(j=0;j<n;j++){
			len=strlen(num[j]);
			result[i]+=(len-1-i>=0?num[j][len-1-i]-'0':0);
		}
		if(result[i]>=10){
			result[i+1]+=result[i]/10;
			result[i]%=10;
		}
	}
	for(i=0;i<105;i++)
		strresult[i]=result[i];
	for(i=0;i<105;i++)
		strresult[i]+='0';
	reverse(strresult);
	printf("%s\n",strresult+strspn(strresult,"0"));
	return 0;
}
