#include<stdio.h>
int main()
{
	int I,t,parity;
	while(scanf("%d",&I),I){
		printf("The parity of ");
		for(t=1<<30;!(t&I);t>>=1);
		parity=1;
		putchar('1');
		for(t>>=1;t;t>>=1){
			if(t&I){
				parity++;
				putchar('1');
			}else
				putchar('0');
		}
		printf(" is %d (mod 2).\n",parity);
	}
	return 0;
}
