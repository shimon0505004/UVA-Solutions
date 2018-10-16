#include<stdio.h>
int main(){
	long long brick[55];
	int length,i;
	brick[1]=brick[0]=1LL;
	for(i=2;i<=50;i++)
		brick[i]=brick[i-1]+brick[i-2];
	while(scanf("%d",&length),length)
		printf("%lld\n",brick[length]);
	return 0;
}
