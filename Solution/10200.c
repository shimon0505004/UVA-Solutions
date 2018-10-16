#include<stdio.h>
#define euler(x) ((x)*(x)+(x)+41)
#define SIZE 10010
char isprime(int n,int prime[]){
	int i;
	for(i=0;prime[i]*prime[i]<=n;i++)
		if(n%prime[i]==0) return 0;
	return 1;
}
int build_prime(int prime[]){
	char not_prime[SIZE]={0};
	int count=0,i,j;
	not_prime[0]=not_prime[1]=1;
	for(i=2;i<SIZE/2;i++){
		if(not_prime[i]) continue;
		prime[count++]=i;
		for(j=2;i*j<SIZE;j++)
			not_prime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++)
		if(!not_prime[i])
			prime[count++]=i;
	return count;
}
int main(){
	int i,n1,n2,result;
	int eulerprime[10001];
	int prime[1231],n_prime;
	n_prime=build_prime(prime);
	eulerprime[0]=1;
	for(i=1;i<=10000;i++)
		eulerprime[i]=eulerprime[i-1]+isprime(euler(i),prime);
	while(scanf("%d%d",&n1,&n2)==2){
		if(n1) result=(int)((double)(eulerprime[n2]-eulerprime[n1-1])/(n2-n1+1)*10000+0.5);
		else result=(int)((double)(eulerprime[n2])/(n2+1)*10000+0.5);
		printf("%d.%.2d\n",result/100,result%100);
	}
	return 0;
}
