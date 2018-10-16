#include<stdio.h>
#include<math.h>
int main()
{
	long double a,b,c,s,r;
	while(scanf("%Lf%Lf%Lf",&a,&b,&c)!=EOF){
		if(a+b+c==0){
			printf("The radius of the round table is: 0.000\n");
			continue;
		}
		s=(a+b+c)/2;
		r=sqrt((s-a)*(s-b)*(s-c)/s);
		printf("The radius of the round table is: %.3Lf\n",r);
	}
	return 0;
}
