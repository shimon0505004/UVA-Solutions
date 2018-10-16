#include<stdio.h>
int main()
{
	int cases,a,b;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&a,&b);
		if(a<b||((a+b)%2)) puts("impossible");
		else
			printf("%d %d\n",(a+b)/2,(a-b)/2);
	}
	return 0;
}
