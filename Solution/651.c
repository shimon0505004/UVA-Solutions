#include<stdio.h>
int main(){
	double deck[100000];
	int i,n;
	deck[0]=0.0;
	for(i=1;i<100000;i++)
		deck[i]=deck[i-1]+(double)1.0/(i<<1);
	puts("# Cards Overhang");
	while(scanf("%d",&n)==1)
		printf("%5d%10.3lf\n",n,deck[n]);
	return 0;
}
