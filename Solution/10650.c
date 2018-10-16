#include<stdio.h>
#define maxn 32010
int prime[maxn]={0};
int primen[3438];
int primeDis[3438];
char isprime(int n){
	int i;
	if(n<maxn) return prime[n];
	for(i=0;primen[i]*primen[i]<=n;i++)
		if(n%primen[i]==0) return 1;
	return 0;
}
int main(){
	int i,j,count=0;
	int L,U,D;
	int output[10];
	for(i=0;i<maxn;i++) prime[i]=1;
	prime[0]=prime[1]=0;
	for(i=2;i<maxn/2;i++){
		if(!prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=0;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]) primen[count++]=i;
	for(i=0;i<count-1;i++)
		prime[primen[i]]=primen[i+1]-primen[i];
	while(scanf("%d%d",&L,&U),L+U){
		if(L>U){
			int temp=L;
			L=U,U=temp;
		}
		for(i=L;i<=U;i++){
			D=prime[i];
			if(D&&prime[i+D]==D&&prime[i-D]!=D){
				count=0;
				output[count++]=i;
				for(j=i;prime[j]==D;j+=D)
					output[count++]=j+D;
				if(output[count-1]<=U){
					printf("%d",output[0]);
					for(j=1;j<count;j++)
						printf(" %d",output[j]);
					puts("");
				}
				i=output[count-1]-1;
			}
		}
	}
	return 0;
}
