#include<stdio.h>
#include<string.h>
#define MAXN 46348
int primen[4792];
int p_count=0;
void build_primen(){
	char isprime[MAXN]={0};
	int i,j;
	isprime[0]=isprime[1]=1;
	for(i=2;i<MAXN/2;i++){
		if(isprime[i]) continue;
		primen[p_count++]=i;
		for(j=2;i*j<MAXN;j++) isprime[i*j]=1;
	}
	for(j=MAXN/2;j<MAXN;j++) if(isprime[j]==0) primen[p_count++]=j;
}
int main(){
	int n,t,i,relat_prime;
	int factor,counter;
	build_primen();
	while(scanf("%d",&n)==1){
		t=relat_prime=n;
		factor=1;
		for(i=0;i<4792&&primen[i]*primen[i]<=t;i++){
			if(t%primen[i]==0) relat_prime/=primen[i],relat_prime*=(primen[i]-1);
			for(counter=0;t%primen[i]==0;counter++) t/=primen[i];
			factor*=counter+1;
		}
		if(t>1) relat_prime/=t,relat_prime*=t-1,factor*=2;
		printf("%d\n",n-factor-relat_prime+1);
	}
	return 0;
}
