#include<stdio.h>
#define max 1000000
int d(int n)
{
	int temp=n;
	while(n){
		temp+=(n%10);
		n/=10;
	}
	return temp;
}
int main()
{
	int i,temp;
	char selfnumber[max+5]={0};
	for(i=1;i<=max;i++){
		if(!selfnumber[i]) printf("%d\n",i);
		if((temp=d(i))>=max) continue;
		selfnumber[temp]=1;
	}
	return 0;
}
