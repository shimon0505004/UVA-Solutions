#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxn 32768
int main()
{
	char inputprime[100],*tokenPtr;
	int actualn,p,e,i,j,start,n;
	char prime[maxn]={0};
	for(i=2;i<maxn;i++){
		if(prime[i]) continue;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	while(1){
		fgets(inputprime,100,stdin);
		tokenPtr=strtok(inputprime," ");
		if(*inputprime=='0') break;
		actualn=1;
		while(tokenPtr!=NULL){
			p=atoi(tokenPtr);
			tokenPtr=strtok(NULL," ");
			e=atoi(tokenPtr);
			tokenPtr=strtok(NULL," ");
			actualn*=(pow(p,e));
		}
		actualn--;
		start=0;
		for(i=actualn;i>=2;i--){
			if(prime[i]) continue;
			n=0;
			while(!(actualn%i)){
				n++;
				actualn/=i;
			}
			if(n){
				if(start) printf(" ");
				start=1;
				printf("%d %d",i,n);
			}
		}
		printf("\n");

	}
	return 0;
}
