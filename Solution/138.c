#include<stdio.h>
#include<math.h>
int main()
{
	int count=0;
	long long s=2,test;
	double cp;
	while(count<10){
		cp=(double)sqrt(2*s*s+1);
		test=(unsigned long)cp;
		if(test==cp){
			printf("%10lld%10lld\n",test*s,2*s*s);
			count++;
		}
		cp=(double)sqrt(2*s*s-1);
		test=(unsigned long)cp;
		if(test==cp){
			printf("%10lld%10lld\n",test*s,2*s*s-1);
			count++;
		}
		s++;
	}
	return 0;
}
