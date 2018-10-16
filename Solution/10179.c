#include<stdio.h>
#define maxn 31630
char prime[maxn]={0};
int primen[3402],count=0;
int main()
{
	int i,j,count=0,n,t;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	while(scanf("%d",&n),n){
		t=n;
		for(j=0;primen[j]*primen[j]<=n;j++)
			if(n%primen[j]==0){
				while(t%primen[j]==0) t/=primen[j];
				n=n/primen[j]*(primen[j]-1);
			}
		if(t>1) n=n/t*(t-1);
		printf("%d\n",n);
	}
	return 0;
}
