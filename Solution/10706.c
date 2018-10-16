#include<stdio.h>
int digits(int);
int main()
{
	unsigned i,n,p,previous,notover;
	int len,cases,count;
	char test[10];
	scanf("%d",&cases);
	for(count=0;count<cases;count++){
		scanf("%u",&n);
		p=0;
		previous=0;
		for(i=1;;i++){
			previous+=digits(i);
			if(p+previous>=n){
				notover=i;
				break;
			}
			p+=previous;
		}
		for(i=1;i<=notover;i++)
			if(p+digits(i)>=n){
				len=digits(i);
				sprintf(test,"%u",i);
				printf("%c\n",test[n-p-1]);
				break;
			}
			else
				p+=digits(i);
	}
	return 0;
}
int digits(int n)
{
	if(n<10)
		return 1;
	else if(n<100)
		return 2;
	else if(n<1000)
		return 3;
	else if(n<10000)
		return 4;
	else if(n<100000)
		return 5;
	else if(n<1000000)
		return 6;
	else if(n<10000000)
		return 7;
	else if(n<100000000)
		return 8;
	else if(n<1000000000)
		return 9;
	else
		return 10;
}
