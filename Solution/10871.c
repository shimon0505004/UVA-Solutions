#include<stdio.h>
#define maxn 10005
char prime[maxn]={0};
int primen[1230];
char isprime(int n){
	int i;
	if(n<maxn) return !prime[n];
	for(i=0;primen[i]*primen[i]<=n;i++)
		if(n%primen[i]==0) return 0;
	return 1;
}
int main(){
	int i,j,count=0,n,k;
	int seq[10005];
	int subsum[10005],cases;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		subsum[0]=0;
		for(i=0;i<n;i++)
			scanf("%d",&seq[i]),subsum[i+1]=subsum[i]+seq[i];
		for(i=2;i<=n;i++){
			for(j=i;j<=n;j++)
				if(isprime(subsum[j]-subsum[j-i])){
					printf("Shortest primed subsequence is length %d:",i);
					for(k=j-i;k<j;k++)
						printf(" %d",seq[k]);
					puts("");
					break;
				}
			if(j<=n) break;
		}
		if(i>n)
			puts("This sequence is anti-primed.");
	}
	return 0;
}
