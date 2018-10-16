#include<stdio.h>
#include<string.h>
int C(int N,int M){
	int i,result;
	result=1;
	M=(N-M<M?N-M:M);
	for(i=1;i<=M;i++){
		result*=N-M+i;
		result/=i;
	}
	return result;
}
int main()
{
	char input[6];
	int i,len,j,tot,t;
	while(scanf("%s",input)==1){
		len=strlen(input);
		for(i=1;i<len;i++)
			if(input[i]<=input[i-1]) break;
		if(i<len){
			puts("0");
			continue;
		}
		tot=0;
		for(i=1;i<len;i++)
			tot+=C(26,i);
		for(i=0;i<input[0]-'a';i++)
			tot+=C(25-i,len-1);
		for(i=0;i<len-1;i++){
			for(j=input[i]+1-'a';j<input[i+1]-'a';j++)
				tot+=C(26-j-1,len-i-2);
		}
		tot++;
		printf("%d\n",tot);
	}
	return 0;
}
