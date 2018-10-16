#include<stdio.h>
#include<string.h>
int trans(char m[],int base){
	int result=0,len=strlen(m),i;
	result=m[0]-'0';
	for(i=1;i<len;i++){
		result*=base;
		result+=m[i]-'0';
	}
	return result;
}
void print(int t,int base){
	if(t){
		print(t/base,base);
		putchar(t%base+'0');
	}
}
int main()
{
	int b,mod,len,i,t;
	char p[1005];
	char m[10];
	while(scanf("%d%s%s",&b,&p,&m),b){
		mod=trans(m,b);
		len=strlen(p);
		t=p[0]-'0';
		for(i=1;i<len;i++){
			t*=b;
			t+=p[i]-'0';
			t%=mod;
		}
		if(t==0) printf("0");
		else print(t,b);
		puts("");
	}
	return 0;
}
