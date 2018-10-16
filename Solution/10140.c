#include<stdio.h>
int main()
{
	int i,j,n=1;
	unsigned t,L,U,prime[4800],previous,max[3],min[3];
	int q[1000003];
	prime[0]=2;
	for(i=3;i<=46349;i++){
		int check = 1 ;
		for(j=0;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0){
				check = 0 ;
				break;
			}
		if(check == 1)
			prime[n++] = i ;
	}
	while(scanf("%u%u",&L,&U)==2){
		memset(q,0,sizeof(q));
		for(i=0;prime[i]*prime[i]<=U;i++){
			if(L<=prime[i])
				t=2*prime[i];
			else if(L%prime[i])
				t=L+prime[i]-(L%prime[i]);
			else
				t=L;
			for(;t<=U;t+=prime[i])
				q[t-L]=1;
		}
		if(L==1) q[0]=1;
		previous=0,max[0]=0,min[0]=1000004;
		for(i=L;i<=U;i++){
			if(!q[i-L]){
				if(previous){
					if(i-previous>max[0]){
						max[1]=previous;
						max[2]=i;
						max[0]=i-previous;
					}
					if(i-previous<min[0]){
						min[1]=previous;
						min[2]=i;
						min[0]=i-previous;
					}
				}
				previous=i;
			}
		}
		if(max[0])
			printf("%u,%u are closest, %u,%u are most distant.\n",min[1],min[2],max[1],max[2]);
		else
			puts("There are no adjacent primes.");
	}
	return 0;
}
