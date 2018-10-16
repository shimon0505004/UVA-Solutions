#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
char result[40];
void add(char *dest,char *source){
	int len1=strlen(dest),len2=strlen(source);
	int max=MAX(len1,len2),min=MIN(len1,len2);
	int i;
	dest[0]=dest[0]+source[0]-'0'*2;
	for(i=1;i<min;i++)
		dest[i]=dest[i]+source[i]-'0'*2;
	for(i=min;i<max;i++)
		dest[i]=dest[i]+source[i]-'0';
	for(i=1;i<=max;i++){
		dest[i]+=dest[i-1]/10;
		dest[i-1]%=10;
	}
	if(dest[max]>0) max++;
	for(i=0;i<max;i++)
		dest[i]+='0';
}
void subtract(char *num){
	int i,len=strlen(num);
	for(i=0;i<len;i++){
		if(num[i]!='0'){
			num[i]--;
			break;
		}else
			num[i]='9';
	}
	if(num[len-1]=='0')
		num[len-1]=0;
}
void multiply(char *dest,char *source){
	int i,j,len1=strlen(dest),len2=strlen(source);
	char r[40]={0};
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			r[i+j]+=(dest[i]-'0')*(source[j]-'0');
			if(r[i+j]>=10){
				r[i+j+1]+=r[i+j]/10;
				r[i+j]%=10;
			}
		}
	}
	for(i=0;i<len1+len2-1;i++)
		r[i]+='0';
	if(r[len1+len2-1]!=0) r[len1+len2-1]+='0';
	strcpy(dest,r);
}
void divide(char *num,int n){
	int i,len=strlen(num);
	char r[40]={0};
	int t;
	t=0;
	for(i=len-1;i>=0;i--){
		t+=num[i]-'0';
		r[i]=t/n+'0';
		t%=n;
		t*=10;
	}
	if(r[len-1]=='0') r[len-1]=0;
	strcpy(num,r);
}
void cal(){
	char temp[40],temp2[40];
	strcpy(temp,result);
	subtract(temp);
	strcpy(temp2,temp);
	multiply(temp,result);
	divide(temp,2);
	strcpy(result,temp);
	subtract(temp2);
	multiply(temp,temp2);
	divide(temp,3);
	subtract(temp2);
	multiply(temp,temp2);
	divide(temp,4);
	add(result,temp);
	memset(temp,0,sizeof(temp));
	temp[0]='1';
	add(result,temp);
}
int main()
{
	char temp[11];
	int cases,len,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",temp);
		if(!strcmp(temp,"0"))
			puts("1");
		else if(!strcmp(temp,"1"))
			puts("1");
		else if(!strcmp(temp,"2"))
			puts("2");
		else if(!strcmp(temp,"3"))
			puts("4");
		else{
			len=strlen(temp);
			memset(result,0,sizeof(result));
			for(i=0;i<len;i++)
				result[len-i-1]=temp[i];
			cal();
			for(i=39;i>=0&&result[i]==0;i--);
			for(;i>=0;i--) putchar(result[i]);
			puts("");
		}
	}
	return 0;
}
