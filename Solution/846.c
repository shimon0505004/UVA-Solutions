#include<stdio.h>
#include<math.h>
int main()
{
	int cases;
	int a,b;
	int step;
	int sqr;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&a,&b);
		step=b-a;
		if(!(b-a)){
			printf("0\n");
			continue;
		}
		sqr=(int)floor(sqrt(step));
		if(sqr*sqr==step)
			printf("%d\n",2*sqr-1);
		else
			if((step-sqr*sqr)<=sqr)
				printf("%d\n",2*sqr);
			else
				printf("%d\n",2*sqr+1);
	}
	return 0;
}
