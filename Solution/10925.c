#include<stdio.h>
#include<string.h>
void reverse(char *s){
	int i,len=strlen(s);
	char temp;
	for(i=0;i<len/2;i++)
		temp=s[i],s[i]=s[len-i-1],s[len-i-1]=temp;
	return;
}
void addall(char sum[],char num[][30],int N){
	int temp,carry=0,i,j;
	for(i=0;i<30;i++){
		temp=carry;
		for(j=0;j<N;j++)
			temp+=num[j][i];
		carry=temp/10,sum[i]=temp%10+'0';
	}
	for(i=29;i>=0;i--)
		if(sum[i]=='0') sum[i]=0;
		else break;
	reverse(sum);
	return;
}
void divide(char sum[],int F){
	char result[30];
	int temp=0,i;
	for(i=29;i>0;i--)
		result[i]=temp/F+'0',temp=(temp%F)*10+sum[i-1];
	result[0]=temp/F+'0';
	for(i=29;i>=0;i--)
		if(result[i]=='0') result[i]=0;
		else break;
	reverse(result);
	strcpy(sum,result);
}
void char_To_int(char num[]){
	int i,len=strlen(num);
	for(i=0;i<len;i++) num[i]-='0';
	return;
}
int main(){
	int N,F,i,j,cases=1;
	char num[1005][30],sum[30];
	while(scanf("%d%d",&N,&F),N+F){
		memset(num,0,sizeof(num));
		for(i=0;i<N;i++) scanf("%s",num[i]),reverse(num[i]),char_To_int(num[i]);
		addall(sum,num,N);
		printf("Bill #%d costs %s:",cases++,strcmp(sum,"")?sum:"0");
		reverse(sum),char_To_int(sum);
		divide(sum,F);
		printf(" each friend should pay %s\n",strcmp(sum,"")?sum:"0");
		puts("");
	}
	return 0;
}
