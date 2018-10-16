#include<stdio.h>
#define SIZE 1000000
#define UBOUND 2000000
int n_prime=0;
char notprime[SIZE]={0};
int prime[78498]={0};
long long basic[7];
int n_factor,min;
void build_prime(){
	int i,j;
	for(i=2;i<SIZE/2;i++){
		if(notprime[i]) continue;
		prime[n_prime++]=i;
		for(j=2;i*j<SIZE;j++)
			notprime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++) if(!notprime[i]) prime[n_prime++]=i;
}
void dfs(int depth,long long now,int n){
	int i;
	long long next=now*basic[depth];
	if(now>=min) return;
	if(depth==n_factor){
		if(now>n) min=now;
		return;
	}
	for(i=1;next<UBOUND;i++){
		dfs(depth+1,next,n);
		next*=basic[depth];
	}
}
void print_next_same_factored(int n){
	int i,t;
	if(n==1){
		puts("Not Exist!");
		return;
	}
	n_factor=0;
	for(i=0,t=n;prime[i]*prime[i]<=t;i++)
		if(t%prime[i]==0){
			while(t%prime[i]==0) t/=prime[i];
			basic[n_factor++]=prime[i];
		}
	if(t>1) basic[n_factor++]=t;
	min=UBOUND;
	dfs(0,1LL,n);
	if(min==UBOUND) puts("Not Exist!");
	else printf("%d\n",min);
	return;
}
int main(){
	int n;
	build_prime();
	while(scanf("%d",&n)==1) print_next_same_factored(n);
	return 0;
}
