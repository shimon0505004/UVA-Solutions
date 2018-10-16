#include<stdio.h>
#define maxn 1000005
int main(){
	char prime[maxn]={0};
	int abacus[maxn]={0};
	int primen[78499]={0};
	int i,j,count=0,n,cases,ptr,result;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		abacus[i]=count;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i,abacus[i]=count;
	for(cases=1;scanf("%d",&n),n;cases++){
		result=0;
		for(i=0;primen[i]*2<n;i++){
			ptr=n-primen[i]+1;
			while(abacus[--ptr]==0);
			result+=abacus[ptr]-abacus[primen[i]];
		}
		printf("Case %d: %d\n",cases,result);
	}
	return 0;
}
