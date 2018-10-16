#include<stdio.h>
int divisorsum(int num)
{
	int result=0,i;
	for(i=1;i<num;i++)
		if(num%i==0)
			result+=i;
	return result;
}
int main()
{
	int num,sum;
	printf("PERFECTION OUTPUT\n");
	while(1){
		scanf("%d",&num);
		if(num==0){
			printf("END OF OUTPUT\n");
			break;
		}
		sum=divisorsum(num);
		if(num<sum)
			printf("%5d  ABUNDANT\n",num);
		else if(num==sum)
			printf("%5d  PERFECT\n",num);
		else
			printf("%5d  DEFICIENT\n",num);
	}
	
	return 0;
}
