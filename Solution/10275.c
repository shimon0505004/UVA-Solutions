#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int mod11(int base,int power){
	int res=1,i;
	for(i=0;i<power;i++)
		res=(res*base)%11;
	return res;
}
int main(){
	char input[500000];
	int digits[100000+5],*ptr;
	int cases,d,number,input_mod,mod;
	int i;
	for(i=1;i<=100004;i++)
		digits[i]=(int)floor(i*log10(i)+1e-6)+1;
	scanf("%d ",&cases);
	while(cases--){
		fgets(input,500000,stdin);
		d=strlen(input)-1;
		if(d==1){
			if(*input=='4') puts("2");
			else if(*input=='1') puts("1");
			else puts("-1");
			continue;
		}
		ptr=bsearch(&d,digits+1,100004,sizeof(int),compar);
		number=ptr-digits;
		input_mod=0;
		for(i=0;i<d;i++) input_mod+=((i&1)*2-1)*(input[i]-'0');
		if(d%2==1) input_mod*=-1;
		input_mod=(11+input_mod%11)%11;
		mod=mod11(number%11,number%10);
		if(input_mod==mod) printf("%d\n",number);
		else puts("-1");
	}
	return 0;
}
