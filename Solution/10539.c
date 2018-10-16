#include<stdio.h>
#define maxn 1000000
int main()
{
	int cases;
	long long low,high,test;
	long long i,j,n=1;
	long long prime[78500]={0};
	prime[0]=2;
	for(i=3;prime[n-1]<maxn;i++){
		int check = 1 ;
		for(j=0;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0){
				check = 0 ;
				break;
			}
		if(check == 1) prime[n++] = i ;
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%lld%lld",&low,&high);
		n=0;
		for(i=0;prime[i]*prime[i]<=high;i++){
			for(test=prime[i]*prime[i];test<=high;test*=prime[i])
				if(test<low) continue;
				else n++;
		}
		printf("%d\n",n);
	}
	return 0;
}
