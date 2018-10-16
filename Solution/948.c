#include<stdio.h>
void printFibonaccimal(int N,int fib[]){
	int i;
	if(N==0) printf("0");
	else{
		for(i=39;i>=0&&fib[i]>N;i--);
		for(;i>=0;i--){
			if(fib[i]<=N){
				putchar('1');
				N-=fib[i];
			}else putchar('0');
		}
	}
}
int main(){
	int fib[40];
	int i,cases,N;
	fib[0]=1,fib[1]=2;
	for(i=2;i<40;i++)
		fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		printf("%d = ",N);
		printFibonaccimal(N,fib);
		printf(" (fib)\n");
	}
	return 0;
}
