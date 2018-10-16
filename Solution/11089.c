#include<stdio.h>
#define SIZE 45
int main(){
	int fib[SIZE];
	int i;
	int cases,n;
	fib[0]=fib[1]=1;
	for(i=2;i<SIZE;i++) fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=SIZE-1;i>0&&fib[i]>n;i--);
		for(;i>=1;i--)
			if(fib[i]<=n) putchar('1'),n-=fib[i];
			else putchar('0');
		puts("");
	}
	return 0;
}
