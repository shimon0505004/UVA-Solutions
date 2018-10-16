#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int N,M,m,i;
	double C;
	while(scanf("%d%d",&N,&M)==2){
		C=0;
		m=(N-M<M?N-M:M);
		for(i=1;i<=m;i++){
			C+=log10(N-m+i);
			C-=log10(i);
		}
		C=floor(C)+1;
		printf("%.0lf\n",C);
	}
	return 0;
}
