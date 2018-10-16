#include<stdio.h>
int f91(int);
int main()
{
	int i,n;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		if(n>100)
			printf("f91(%d) = %d\n",n,n-10);
		else
			printf("f91(%d) = %d\n",n,91);
	}
	return 0;
}
int f91(int n)
{
	if(n>100)
		return n-10;
	else
		return f91(f91(n+11));
}
