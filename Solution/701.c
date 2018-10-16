#include<stdio.h>
#include<math.h>
#define log_2(x) (log(x)/log(2))
int main(){
	int N,len;
	const double log2_10=log_2(10);
	double Ubound,Lbound,E;
	while(scanf("%d",&N)==1){
		len=(int)(log10(N)+1)+1;
		Ubound=log_2(N+1);
		Lbound=log_2(N);
		for(;;len++)
			if(ceil(Lbound+log2_10*len)<Ubound+log2_10*len) break;
		printf("%.0lf\n",ceil(Lbound+log2_10*len));
	}
	return 0;
}
