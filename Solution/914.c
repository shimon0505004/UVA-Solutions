#include<stdio.h>
#include<string.h>
#define SIZE 1000005
#define N_PRIME 78499
struct VECTOR{
	int dis[58];
}vec[N_PRIME];
void copy(struct VECTOR *dest,struct VECTOR *src){
	memcpy(dest,src,sizeof(struct VECTOR));
}
void subtract(struct VECTOR *dest,struct VECTOR *src1,struct VECTOR *src2){
	int i;
	for(i=0;i<58;i++)
		dest->dis[i]=src2->dis[i]-src1->dis[i];
}
void build_prime(int prime[]){
	char notprime[SIZE]={0};
	int i,j,count=0;
	for(i=2;i<SIZE/2;i++){
		if(notprime[i]) continue;
		prime[count++]=i;
		for(j=2;i*j<SIZE;j++)
			notprime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++)
		if(!notprime[i])
			prime[count++]=i;
}
int main(){
	int prime[N_PRIME];
	int i,cases,L,U,pL,pU;
	struct VECTOR v;
	build_prime(prime);
	memset(vec,0,sizeof(vec));
	for(i=1;i<N_PRIME;i++){
		copy(&vec[i],&vec[i-1]);
		vec[i].dis[(prime[i]-prime[i-1])/2]++;
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&L,&U);
		for(pL=0;prime[pL]<L;pL++);
		for(pU=pL;prime[pU]<=U;pU++);
		pU--;
		if(pL>=pU) puts("No jumping champion");
		else{
			int max=0,maxi=-1;
			subtract(&v,&vec[pL],&vec[pU]);
			for(i=0;i<58;i++)
				if(v.dis[i]>max)
					max=v.dis[i],maxi=i;
				else if(v.dis[i]==max)
					maxi=-1;
			if(maxi!=-1) printf("The jumping champion is %d\n",maxi==0?1:maxi*2);
			else puts("No jumping champion");
		}
	}
	return 0;
}
