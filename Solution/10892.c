#include<stdio.h>
#define maxn 44730
char prime[maxn]={0};
int primen[4650],count=0;
int main()
{
	int i,j,count=0,n,result,t,m;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	while(scanf("%d",&n),n){
		result=1,t=n;
		for(i=0;primen[i]*primen[i]<=n;i++){
			for(m=0;t%primen[i]==0;m++)
				t/=primen[i];
			result=2*result*m+result-m;
		}
		if(t>1) result=3*result-1;
		printf("%d %d\n",n,result);
	}
	return 0;
}
