#include<stdio.h>
#include<string.h>
int main(){
	char s[85];
	char input[85];
	int len,i,j,n;
	scanf("%d",&n);
	while(n--){
		scanf(" ");
		memset(s,0,sizeof(s));
		fgets(input,85,stdin);
		for(i=0;i<8;i++){
			fgets(input,85,stdin);
			len=strlen(input)-3;
			for(j=0;j<len;j++)
				if(input[j+1]=='\\') s[j]+=(1<<i);
		}
		fgets(input,85,stdin);
		puts(s);
	}
	return 0;
}
