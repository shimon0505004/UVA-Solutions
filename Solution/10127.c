#include<stdio.h>
int main()
{
	int n;
	int Ones,Num;
	while(scanf("%d",&n)==1){
		Ones=1;
		for(Num=1;Ones%=n;Num++)
			Ones=Ones*10+1;
		printf("%d\n",Num);
	}
	return 0;
}
