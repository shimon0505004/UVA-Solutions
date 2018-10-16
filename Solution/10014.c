#include<stdio.h>
int main()
{
	int cases,i;
	double a0,an1,temp,n,tot;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf",&n);
		scanf("%lf%lf",&a0,&an1);
		tot=0;
		for(i=0;i<n;i++){
			scanf("%lf",&temp);
			tot+=temp*(n-i);
		}
		printf("%.2lf\n",(n*a0-2*tot+an1)/(n+1));
		if(cases) puts("");
	}
	return 0;
}
