#include<stdio.h>
#define maxn 6000000
void goldbach(int,char*);
int main()
{
	char prime[maxn]={0};
	int n,i,j;
	prime[0]=prime[1]=0;
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	while(scanf("%d",&n)==1){
		if(n<8)
			printf("Impossible.\n");
		else if(n==8)
			printf("2 2 2 2\n");
		else if(n==9)
			printf("2 2 2 3\n");
		else{
			if(!(n%2)){
				printf("2 2 ");
				goldbach(n-4,prime);
			}
			else{
				printf("2 3 ");
				goldbach(n-5,prime);
			}
		}
	}
	return 0;
}
void goldbach(int n,char*prime)
{
	int i;
	if(n==4){
		printf("2 2\n");
		return;
	}
	for(i=n/2;;i--)
		if(!(prime[i]+prime[n-i])){
			printf("%d %d\n",i,n-i);
			return;
		}
}
