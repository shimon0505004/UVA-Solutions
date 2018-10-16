#include<stdio.h>
int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)==2&&N){
		printf("%d %d ",N,M);
		if(N==1)
			if(M==1)
				puts("Multiple");		
			else
				puts("Impossible");
		else if((M-1)%(N-1))
			puts("Impossible");
		else
			printf("%d\n",M+(M-1)/(N-1));
	}
	return 0;
}
