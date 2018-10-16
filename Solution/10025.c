#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int cases,answer;
	long long k;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lld",&k);
		if(!k)
			puts("3");
		else{
			k=abs(k);
			answer=(int)ceil((double)(-1+sqrt(1+8*k))/2);
			if((((answer+1)/2)%2)!=(k%2)){
				if(answer%2)
					answer+=2;
				else
					answer++;
			}
			printf("%d\n",answer);
		}
		if(cases) puts("");
	}
	return 0;
}
