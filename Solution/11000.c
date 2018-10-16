#include<stdio.h>
int main(){
	unsigned fib[47];
	int i,N;
	fib[0]=1,fib[1]=1;
	for(i=2;i<47;i++)
		fib[i]=fib[i-1]+fib[i-2];
	while(scanf("%d",&N),N>=0)
		printf("%u %u\n",fib[N+1]-1,fib[N+2]-1);
	return 0;
}
