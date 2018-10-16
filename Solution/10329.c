#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 5005
#define N_PRIME 670
int primen[N_PRIME];
char prime_exp[maxn][N_PRIME]={{0}};
void build_primen(){
	char prime[maxn]={0};
	int i,j,count=0;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
}
void multiply(int p_exp[],int n){
	int i;
	for(i=0;i<N_PRIME;i++)
		p_exp[i]+=prime_exp[n][i];
}
void divide(int p_exp[],int n){
	int i;
	for(i=0;i<N_PRIME;i++)
		p_exp[i]-=prime_exp[n][i];
}
char is_integer(int comb[]){
	int i;
	for(i=0;i<N_PRIME;i++)
		if(comb[primen[i]]<0) return 0;
	return 1;
}
char less_than_101_digit(int comb[]){
	int i;
	double digit=0;
	for(i=0;i<N_PRIME;i++) digit+=log10(primen[i])*comb[primen[i]];
	if(digit+1e-3>100) return 0;
	return 1;
}
void printBigInt(int comb[]){
	int BigInt[105]={0};
	int i,j;
	BigInt[0]=1;
	for(i=0;i<N_PRIME;i++){
		while(comb[primen[i]]--){
			for(j=0;j<105;j++) BigInt[j]*=primen[i];
			for(j=1;j<105;j++) BigInt[j]+=BigInt[j-1]/10,BigInt[j-1]%=10;
		}
	}
	for(i=105-1;BigInt[i]==0;i--);
	for(;i>=0;i--) printf("%d",BigInt[i]);
	puts("");
}
void build_prime_exp(){
	int i,j,n;
	for(i=2;i<maxn;i++)
		for(j=0,n=i;j<N_PRIME;j++)
			while(n%primen[j]==0) prime_exp[i][j]++,n/=primen[j];
}
void print_prime_exp(int p_exp[]){
	int i;
	for(i=0;i<N_PRIME;i++)
		while(p_exp[primen[i]]--)
			printf("%d*",primen[i]);
	puts("");
}
int main(){
	int i,j;
	int M,N,n,r;
	int p_exp[N_PRIME];
	int comb[maxn];
	build_primen();
	build_prime_exp();
	while(scanf("%d%d",&N,&M)==2){
		memset(p_exp,0,sizeof(p_exp));
		memset(comb,0,sizeof(comb));
		while(N--){
			scanf("%d%d",&n,&r);
			if(2*r>n) r=n-r;
			for(i=1;i<=r;i++)
				comb[n-i+1]++,comb[i]--;
		}
		while(M--){
			scanf("%d%d",&n,&r);
			if(2*r>n) r=n-r;
			for(i=1;i<=r;i++)
				comb[n-i+1]--,comb[i]++;
		}
		comb[1]=0;
		for(i=2;i<5001;i++)
			for(j=0;primen[j]<i;j++)
				comb[primen[j]]+=prime_exp[i][j]*comb[i];
		if(is_integer(comb)){
			if(less_than_101_digit(comb))
				printBigInt(comb);
			else puts("-1");
		}else puts("0");
	}
	return 0;
}
