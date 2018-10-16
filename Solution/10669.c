#include<stdio.h>
#include<string.h>
void reverse(char n[]){
	int len=strlen(n),i;
	char temp;
	for(i=0;i<len/2;i++)
		temp=n[i],n[i]=n[len-i-1],n[len-i-1]=temp;
}
int main(){
	unsigned long long N,t;
	char pow_3[64][35]={0},start;
	int i,j;
	pow_3[0][0]='1';
	for(i=1;i<64;i++){
		for(j=0;pow_3[i][j]||pow_3[i-1][j];j++){
			if(pow_3[i-1][j]) pow_3[i][j]+=(pow_3[i-1][j]-'0')*3;
			pow_3[i][j+1]+=pow_3[i][j]/10;
			pow_3[i][j]=pow_3[i][j]%10+'0';
		}
	}
	for(i=0;i<64;i++)
		reverse(pow_3[i]);
	while(scanf("%llu",&N),N--){
		printf("{"),start=0;
		for(t=1LLU,i=0;t<=N;t<<=1,i++)
			if(t&N){
				if(start) printf(",");
				start=1,printf(" %s",pow_3[i]);
			}
		printf(" }\n");
	}
	return 0;
}
