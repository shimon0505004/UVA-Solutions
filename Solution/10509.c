#include<stdio.h>
#include<math.h>
int main()
{
	double input,sqroot,dx;
	while(1){
		scanf("%lf",&input);
		if(!(int)input) break;
		sqroot=floor(pow(input,1.00/3.00)+0.000001);
		if(fabs(sqroot-pow(input,1.00/3.00))<0.00001)
			dx=0.0;
		else
			dx=(input-sqroot*sqroot*sqroot)/(3*sqroot*sqroot);
		printf("%.4lf\n",sqroot+dx);
	}
}
