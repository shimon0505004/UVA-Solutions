#include<stdio.h>
#include<math.h>
#define log2 log10(2)
int main()
{
	double result,head;
	int n;
	while(scanf("%d",&n)!=EOF){
		n*=-1;
		head=floor((double)n*log2);
		printf("2^%d = %.4lfe%.0lf\n",n,pow(10,n*log2-head),head);
	}
	return 0;
}
