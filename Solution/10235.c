#include<stdio.h>
#define maxn 1000000
void reverse(char*num)
{
	char hold;
	int i;
	for(i=0;i<strlen(num)/2;i++){
		hold=num[i];
		num[i]=num[strlen(num)-1-i];
		num[strlen(num)-1-i]=hold;
	}
}
int main()
{
	int i,j,prime[1000001]={0},n,emirp;
	char isprime[10],isemirp[10];
	for(i=2;i<maxn;i++){
		if(prime[i]) continue;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	while(scanf("%d",&n)==1){
		if(prime[n])
			printf("%d is not prime.\n",n);
		else{
			memset(isprime,0,sizeof(isprime));
			sprintf(isprime,"%d",n);
			sprintf(isemirp,"%s",isprime);
			reverse(isemirp);
			emirp=atoi(isemirp);
			if(!prime[emirp]&&strcmp(isemirp,isprime))
				printf("%d is emirp.\n",n);
			else
				printf("%d is prime.\n",n);
					
		}
	}
	return 0;
}
