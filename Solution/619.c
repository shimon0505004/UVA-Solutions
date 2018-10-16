#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define Ubound 30
char expo[21][Ubound]={"1","62","676","67571","679654","67318811","677519803","6710181308","675460728802","6798763059245","673356590761141","6777896844430763","67128616665982459","6756373023782511842","67905179230747990546","6735295275822439527761","67795047882499824780634","6714555270515835137283311","67580446881931000201597492","679226474098163002562764667"};
void reverse(char *s){
	int i,len=strlen(s);
	char c;
	for(i=0;i<len/2;i++)
		c=s[i],s[i]=s[len-i-1],s[len-i-1]=c;
}
void multiply(char *dest,char *source){
	int i,j,len1=strlen(dest),len2=strlen(source);
	char r[Ubound]={0};
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
int divide(char *num){
	int i,len=strlen(num),t=0,n=26;
	for(i=len-1;i>=0;i--){
		t+=num[i]-'0';
		num[i]=t/n+'0';
		t%=n;
		t*=10;
	}
	for(i=len-1;num[i]=='0';i--) num[i]=0;
	return t/10;
}
int main()
{
	char input[Ubound],temp[Ubound],result[Ubound],added[Ubound];
	int i,len,t,j;
	while(scanf("%s",input)==1){
		if(isalpha(*input)){
			memset(result,0,sizeof(result));
			result[0]='0',len=strlen(input);
			for(i=0;i<len;i++){
				memset(temp,0,sizeof(temp));
				strcpy(temp,expo[i]);
				t=input[len-1-i]-'a'+1;
				memset(added,0,sizeof(added));
				for(j=0;t;j++)
					added[j]=t%10+'0',t/=10;
				multiply(temp,added);
				add(result,temp);
			}
			memset(added,0,sizeof(added));
			len=strlen(result);
			printf("%-22s",input);
			for(i=len-1;i>=0;i--){
				putchar(result[i]);
				if(i&&i%3==0) putchar(',');
			}
			puts("");
		}else if(isdigit(*input)){
			len=strlen(input);
			strcpy(temp,input);
			reverse(temp);
			memset(result,0,sizeof(result));
			for(i=0;t=divide(temp);i++)
				result[i]=t-1+'a';
			reverse(result);
			printf("%-22s",result);
			for(i=0;i<len;i++){
				putchar(input[i]);
				if((len-i-1)%3==0&&i<len-1) putchar(',');
			}
			puts("");
		}else break;
	}
	return 0;
}
