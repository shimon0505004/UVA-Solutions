#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int GCD(int a,int b){
	int temp;
	while(a%b) temp=a,a=b,b=temp%b;
	return b;
}
int main(){
	char input[10];
	int num,den,gcd,N;
	int pow_10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	int minden,minnum,i,len;
	while(scanf(" %*c%*c%[^.]%*s",input)==1){
		minden=2147483647;
		N=atoi(input),len=strlen(input);
		for(i=1;i<=len;i++){
			den=pow_10[len]-pow_10[len-i];
			num=N-N/pow_10[i];
			gcd=GCD(den,num);
			if(den/gcd<minden) minden=den/gcd,minnum=num/gcd;
		}
		printf("%d/%d\n",minnum,minden);
	}
	return 0;
}
