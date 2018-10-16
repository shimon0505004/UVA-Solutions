#include<stdio.h>
#include<string.h>
#define MAX_DIGIT 50
void assign(char n1[],char n2[]){
	memcpy(n1,n2,sizeof(char[MAX_DIGIT]));
}
void add(char dest[],char src[]){
	int i;
	for(i=0;i<MAX_DIGIT-1;i++){
		dest[i]+=src[i];
		dest[i+1]+=dest[i]/10;
		dest[i]%=10;
	}
	dest[i]+=src[i];
}
void printBigInt(char n[]){
	int i;
	for(i=MAX_DIGIT-1;i>0&&n[i]==0;i--);
	for(;i>=0;i--)
		printf("%d",n[i]);
	puts("");
}
int main(){
	char BigInt[10005][MAX_DIGIT];
	char pow_2[141][MAX_DIGIT];
	int i,N,rest,index;
	memset(pow_2,0,sizeof(pow_2));
	memset(BigInt,0,sizeof(BigInt));
	pow_2[0][0]=1;
	for(i=1;i<141;i++){
		assign(pow_2[i],pow_2[i-1]);
		add(pow_2[i],pow_2[i-1]);
	}
	index=0,rest=1;
	for(i=1;i<10005;i++){
		assign(BigInt[i],BigInt[i-1]);
		add(BigInt[i],pow_2[index]);
		if(--rest==0) index++,rest=index+1;
	}
	while(scanf("%d",&N)==1)
		printBigInt(BigInt[N]);
	return 0;
}
