#include<stdio.h>
#include<math.h>
#define SIZE ((1<<20)+1)
char NotPrime[SIZE]={0};
int Prime[82025],n_Prime=0;
void makePrime(){
	int i,j;
	NotPrime[0]=NotPrime[1]=1;
	for(i=2;i<SIZE/2;i++){
		if(NotPrime[i]) continue;
		Prime[n_Prime++]=i;
		for(j=2;i*j<SIZE;j++)
			NotPrime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++)
		if(NotPrime[i]==0) Prime[n_Prime++]=i;
}
char is_cpsPrime(int cpsPrime){
	int i;
	if(NotPrime[cpsPrime]==0) return 0;
	for(i=0;i<n_Prime;i++)
		if(cpsPrime%Prime[i]==0){
			if(NotPrime[cpsPrime/Prime[i]]==0) return 1;
			else return 0;
		}
	return 0;
}
int main(){
	int K,cpsPrime;
	int i;
	makePrime();
	while(scanf("%d",&K)==1){
		int n_cpsPrime=0;
		for(i=0;i<K;i++){
			scanf("%d",&cpsPrime);
			if(is_cpsPrime(cpsPrime))
				n_cpsPrime++;
		}
		printf("%d\n",n_cpsPrime);
	}
	return 0;
}
