#include<stdio.h>
int main()
{
	int a,b,temp,n;
	while(scanf("%d%d",&a,&b)==2){
		n=0;
		printf("[");
		while(1){
			if(n==1)
				printf(";");
			else if(n>1)
				printf(",");
			printf("%d",a/b);
			n++;
			if(!(a%b))
				break;
			temp=a%b;
			a=b;
			b=temp;
		}
		printf("]\n");
	}
	return 0;
}
