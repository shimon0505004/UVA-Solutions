#include<stdio.h>
#include<math.h>
int main()
{
	int n,sqr,diff;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		sqr=(int)sqrt(n);
		if(sqr==sqrt(n))
			sqr--;
		diff=n-pow(sqr,2);
		if(sqr%2)
			if(diff<=sqr)
				printf("%d %d\n",diff,sqr+1);
			else{
				diff=2*sqr+2-diff;
				printf("%d %d\n",sqr+1,diff);
			}
		else
			if(diff<=sqr)
				printf("%d %d\n",sqr+1,diff);
			else{
				diff=2*sqr+2-diff;	
				printf("%d %d\n",diff,sqr+1);
			}
	}	
	return 0;
}
