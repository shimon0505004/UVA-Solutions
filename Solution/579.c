#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int hour,min;
	float ans;
	while(1){
		scanf("%u%*c%u",&hour,&min);
		if(hour+min==0) break;
		hour%=12;
		ans=fabs(min*5.5-hour*30);
		if(ans>180) ans=360-ans;
		printf("%.3f\n",ans);
	}
	return 0;
}
