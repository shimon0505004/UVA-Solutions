#include<stdio.h>
#define maxn 250
char prime[maxn]={0};
int primen[53],count=0;
int main()
{
	int i,j,count=0,n,t;
	int table[50005]={0};
	table[1]=1;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	for(i=2;i<50005;i++){
		table[i]=t=i;
		for(j=0;primen[j]*primen[j]<=i;j++)
			if(i%primen[j]==0){
				while(t%primen[j]==0) t/=primen[j];
				table[i]=table[i]/primen[j]*(primen[j]-1);
			}
		if(t>1) table[i]=table[i]/t*(t-1);
		table[i]=(table[i]<<1)+table[i-1];
	}
	while(scanf("%d",&n),n)
		printf("%d\n",table[n]);
	return 0;
}
