#include<stdio.h>
#include<math.h>
int main()
{
	int cases,x,k,fl,ce;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&x,&k);
		fl=floor((double)x/k);
		ce=ceil((double)x/k);
		if(fl==ce)
			printf("%d 0\n",k);
		else
			printf("%d %d\n",-x,x);

	}
	return 0;
}
