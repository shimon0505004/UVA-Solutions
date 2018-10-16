#include<stdio.h>
int main()
{
	int num1,num2;
	int carryopera,n;
	while(1){
		scanf("%d%d",&num1,&num2);
		if(num1+num2==0) break;
		for(n=carryopera=0;num1+num2!=0;num1/=10,num2/=10){
			if(num1%10+num2%10+carryopera>=10){
				n++;
				carryopera=1;
			}
			else
				carryopera=0;
		}
		switch(n){
			case 0:
				printf("No carry operation.\n");
				break;
			case 1:
				printf("1 carry operation.\n");
				break;
			default:
				printf("%d carry operations.\n",n);
		}
	}
	return 0;
}
