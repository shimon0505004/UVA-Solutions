#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1005
char prime[maxn]={0};
int primen[168];
int main(){
	int i,j,count=0;
	int m,n,p,cases=0;
	int factor[maxn],result;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	while(scanf("%d%d%d",&m,&n,&p),m&&n&&p){
		printf("Case %d: ",++cases);
		m=abs(m),n=abs(n),p=abs(p);
		memset(factor,0,sizeof(factor));
		for(i=0;primen[i]*primen[i]<=p;i++)
			while(p%primen[i]==0) factor[primen[i]]+=2,p/=primen[i];
		if(p>1) factor[p]+=2;
		for(i=0;primen[i]*primen[i]<=n;i++)
			while(n%primen[i]==0) factor[primen[i]]++,n/=primen[i];
		if(n>1) factor[n]++;
		for(i=0;primen[i]*primen[i]<=m;i++)
			while(m%primen[i]==0) factor[primen[i]]++,m/=primen[i];
		if(m>1) factor[m]++;
		for(result=1,i=0;i<168;i++)
			if(factor[primen[i]]) result*=factor[primen[i]]+1;
		printf("%d\n",(result<<1)-1);
	}
	return 0;
}
