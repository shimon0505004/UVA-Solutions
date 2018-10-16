#include<stdio.h>
#include<string.h>
#define LENGTH 250
#define MODULO 1000000000
struct BigNum{
	int n[LENGTH];
};
void assign(struct BigNum *dest,struct BigNum *src){
	memcpy(dest,src,sizeof(struct BigNum));
}
void add(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<LENGTH;i++) dest->n[i]+=src->n[i];
	for(i=1;i<LENGTH;i++) dest->n[i]+=dest->n[i-1]/MODULO,dest->n[i-1]%=MODULO;
}
void multiply(struct BigNum *dest,int multiplier){
	long long res[LENGTH];
	int i;
	memset(res,0,sizeof(res));
	for(i=0;i<LENGTH;i++) res[i]=(long long)dest->n[i]*multiplier;
	dest->n[0]=res[0]%MODULO;
	for(i=1;i<LENGTH;i++) res[i]+=res[i-1]/MODULO,dest->n[i]=res[i]%MODULO;
}
void printBigNum(struct BigNum *bignum){
	int i;
	for(i=LENGTH-1;bignum->n[i]==0&&i>0;i--);
	printf("%d",bignum->n[i--]);
	for(;i>=0;i--)
		printf("%.9d",bignum->n[i]);
	puts("");
}
int main(){
	struct BigNum derang[801];
	int n,i;
	memset(derang,0,sizeof(derang));
	derang[0].n[0]=1;
	for(i=2;i<=800;i++){
		assign(&derang[i],&derang[i-2]);
		add(&derang[i],&derang[i-1]);
		multiply(&derang[i],i-1);
	}
	while(scanf("%d",&n),n!=-1)
		printBigNum(&derang[n]);
	return 0;
}
