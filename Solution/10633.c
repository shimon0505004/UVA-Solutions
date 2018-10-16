#include<stdio.h>
#include<string.h>
int main()
{
	unsigned long long input;
	while(1){
		scanf("%llu",&input);
		if(!input) break;
		if(!(input%9))
			printf("%lld %lld\n",input+input/9-1,input+input/9);
		else
			printf("%lld\n",input+input/9);
	}
	return 0;
}
