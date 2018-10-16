#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAXL 151
#define MAXD 10
#define MOD 1000000000
struct BigNum{
	int n[MAXD];
};
void assign(struct BigNum *dest,struct BigNum *src){
	memcpy(dest,src,sizeof(struct BigNum));
}
void multiply(struct BigNum *dest,struct BigNum *src){
	int i,j;
	long long res[MAXD]={0};
	for(i=0;i<MAXD;i++)
		for(j=0;i+j<MAXD;j++)
			res[i+j]+=(long long)dest->n[i]*src->n[j];
	for(i=1;i<MAXD;i++){
		res[i]+=res[i-1]/MOD;
		res[i-1]%=MOD;
	}
	for(i=0;i<MAXD;i++) dest->n[i]=(int)res[i];
}
void add(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<MAXD;i++)
		dest->n[i]+=src->n[i];
	for(i=1;i<=MAXD;i++){
		dest->n[i]+=dest->n[i-1]/MOD;
		dest->n[i-1]%=MOD;
	}
}
void printBigNum(struct BigNum *bignum){
	int i;
	for(i=MAXD-1;i>0&&bignum->n[i]==0;i--);
	if(i==0) printf("%d",bignum->n[i]);
	else{
		printf("%d",bignum->n[i--]);
		for(;i>=0;i--) printf("%.9d",bignum->n[i]);
	}
	puts("");
}
void subtract(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<MAXD-1;i++){
		dest->n[i]=dest->n[i]+MOD-src->n[i];
		dest->n[i+1]+=dest->n[i]/MOD-1;
		dest->n[i]%=MOD;
	}
	dest->n[MAXD-1]-=src->n[MAXD-1];
}
int main(){
	struct BigNum expr[MAXL][MAXL],temp;
	int i,j,k;
	int n,d;
	memset(expr,0,sizeof(expr));
	expr[0][0].n[0]=1;
	for(i=1;i<MAXL;i++){
		for(j=1;j<=i;j++){
			for(k=0;k<i;k++){
				if(k<j-1) assign(&temp,&expr[k][k]);
				else assign(&temp,&expr[k][j-1]);
				if(i-k-1<j) multiply(&temp,&expr[i-k-1][i-k-1]);
				else multiply(&temp,&expr[i-k-1][j]);
				add(&expr[i][j],&temp);
			}
		}
	}
	for(i=1;i<MAXL;i++)
		for(j=i;j>=1;j--)
			subtract(&expr[i][j],&expr[i][j-1]);
	while(scanf("%d%d",&n,&d)==2){
		if(n%2==1) puts("0");
		else printBigNum(&expr[n/2][d]);
	}
	return 0;
}
