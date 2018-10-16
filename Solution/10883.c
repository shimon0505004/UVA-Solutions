#include<stdio.h>
#include<math.h>
int main()
{
	int cases,n,i,j;
	double result,C,temp;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		scanf("%d",&n);
		result=0,C=-log(2)*(n-1);
		for(j=0;j<n;j++){
			scanf("%lf",&temp);
			result+=temp*exp(C);
			C+=log(n-j-1)-log(j+1);
		}
		printf("Case #%d: %.3lf\n",i,result);
	}
	return 0;
}
