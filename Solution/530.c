#include<stdio.h>
int main()
{
	unsigned int N,M,m,i;
	long long C;
	while(1){
		scanf("%d%d",&N,&M);
		if(N+M==0) break;
		C=1;
		m=(N-M<M?N-M:M);
		for(i=1;i<=m;i++){
			C*=N-m+i;
			C/=i;
		}
		printf("%lld\n",C);
	}
	return 0;
}
