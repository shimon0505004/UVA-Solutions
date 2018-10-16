#include<stdio.h>
#define SIZE 1000000
char is_circular(int p,char notprime[]){
	int digits,i;
	int pow_10[7]={1,10,100,1000,10000,100000,1000000};
	for(digits=0;pow_10[digits]<p;digits++);
	for(i=0;i<digits;i++){
		int next=(p%10)*pow_10[digits-1]+p/10;
		if(notprime[next]) return 0;
		p=next;
	}
	return 1;
}
void build_circular(int circular[]){
	char notprime[SIZE]={0};
	int prime[78500];
	int i,j,count=0;
	notprime[0]=notprime[1]=1;
	for(i=2;i<SIZE/2;i++){
		if(notprime[i]) continue;
		prime[count++]=i;
		for(j=2;i*j<SIZE;j++)
			notprime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++)
		if(!notprime[i]) prime[count++]=i;
	for(i=0;i<count;i++){
		if(is_circular(prime[i],notprime))
			circular[prime[i]]=1;
	}
}
int main(){
	int circular[SIZE]={0};
	int i,L,U;
	build_circular(circular);
	for(i=1;i<SIZE;i++)
		circular[i]+=circular[i-1];
	while(scanf("%d%d",&L,&U),L>0){
		int ans=circular[U]-circular[L-1];
		if(ans==0) puts("No Circular Primes.");
		else if(ans==1) puts("1 Circular Prime.");
		else printf("%d Circular Primes.\n",ans);
	}
	return 0;
}
