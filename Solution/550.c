#include<stdio.h>
int main()
{
	int base,digit,multi,temp,count;
	while(scanf("%d%d%d",&base,&digit,&multi)==3){
		count=1;
		for(temp=digit*multi;temp!=digit;count++)
			temp=temp/base+(temp%base)*multi;
		printf("%d\n",count);
	}
	return 0;
}
