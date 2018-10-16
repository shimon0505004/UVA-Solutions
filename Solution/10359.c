#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define Ubound 80
char Tiling[251][Ubound]={0};
void add(char *dest,char *source){
	int len1=strlen(dest),len2=strlen(source),i;
	int max=MAX(len1,len2),min=MIN(len1,len2);
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
int main()
{
	int i,j,len,n;
	Tiling[0][0]=Tiling[1][0]='1';
	for(i=2;i<=250;i++){
		strcpy(Tiling[i],Tiling[i-2]);
		len=strlen(Tiling[i]);
		for(j=0;j<len;j++)
			Tiling[i][j]+=(Tiling[i][j]-'0');
		add(Tiling[i],Tiling[i-1]);
	}
	while(scanf("%d",&n)==1){
		len=strlen(Tiling[n]);
		while(len--)
			putchar(Tiling[n][len]);
		puts("");
	}
	return 0;
}
