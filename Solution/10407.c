#include<stdio.h>
#include<stdlib.h>
int GCD(int a,int b)
{
	int temp;
	while(a%b){
		a%=b;
		temp=a,a=b,b=temp;
	}
	return b;
}
int main()
{
	int i,count,gcd;
	int div[1002];
	while(1){
		for(count=0;scanf("%d",&div[count])&&div[count];count++);
		if(!count) break;
		for(i=1;i<count;i++)
			div[i]=abs(div[i]-*div);
		gcd=div[1];
		for(i=2;i<count;i++)
			if(div[i])
				gcd=GCD(gcd,div[i]);
		printf("%d\n",gcd);
	}
	return 0;
}
