#include<stdio.h>
#include<math.h>
int main()
{
	int i,negative,test;
	double n;
	while(scanf("%lf",&n)==1&&n){
		negative=0;
		if(n==-1<<31){
			printf("31\n");
			continue;
		}
		if(n<0){
			n*=-1;
			negative=1;
		}
		for(i=32;i>=1;i--){
			test=(int)(pow(n,(double)1/i)+0.000001);
			if(n==pow((double)test,(double)i)){
				if(!(i%2)&&negative){
					test=i;
					while(!(test%2))
						test/=2;
					printf("%d\n",test);
				}
				else
					printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
