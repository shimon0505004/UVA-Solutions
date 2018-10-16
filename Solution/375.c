#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
int main()
{
	int cases,i;
	double B,H,R,s,result,rate;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		if(i) printf("\n");
		scanf("%lf%lf",&B,&H);
		R=(B*H)/(2*sqrt(H*H+(B*B/4.0))+B);
		rate=(H-2*R)/H;
		for(result=0.0;R>=0.000001;R*=rate)
			result+=2*pi*R;
		printf("%13.6lf\n",result);
	}
	return 0;
}
