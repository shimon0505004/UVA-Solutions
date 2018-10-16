#include<stdio.h>
#define maxn 1000
int main()
{
	int i,n = 2,j,num,N,C;
	int prime[170]={0};
	prime[0]=1;
	prime[1]=2;
	for(i=3;prime[n]<maxn;i++){
		int check = 1 ;
		for(j=1;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0){
				check = 0 ;
				break;
			}
		if(check == 1) prime[n++] = i ;
	}
	while(scanf("%d%d",&N,&C)!=EOF){
		printf("%d %d:",N,C);
		for(i=0;;i++)
			if(prime[i]>N){
				if(i%2)
					if(2*C-1>=i)
						for(j=0;j<i;j++)
							printf(" %d",prime[j]);
					else
						for(j=0;j<2*C-1;j++)
							printf(" %d",prime[(i+1)/2-C+j]);
				else
					if(2*C>=i)
						for(j=0;j<i;j++)
							printf(" %d",prime[j]);
					else
						for(j=0;j<2*C;j++)
							printf(" %d",prime[i/2-C+j]);
				
				break;
			}
		printf("\n\n");
	}
	return 0;
}
