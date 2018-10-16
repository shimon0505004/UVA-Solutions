#include<stdio.h>
int main()
{
	long long A,L,a;
	int cases=0,terms;
	while(1){
		scanf("%lld%lld",&A,&L);
		if(A+L<0) break;
		a=A;
		cases++;
		terms=1;
		while(1){
			if(a%2==0)
				a/=2;
			else
				a=a*3+1;
			if(a>L) break;
			terms++;
			if(a==1) break;
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",cases,A,L,terms);
	}
	return 0;
}
