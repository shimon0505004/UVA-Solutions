#include<stdio.h>
int main()
{
	unsigned int n,i,p;
	while(scanf("%d",&n)==1){
		p=1;
		for(i=0;p<n;i++)
			if(i%2)
				p*=2;
			else
				p*=9;
		if(i%2)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
	return 0;
}
