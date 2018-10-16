#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int cases,total,i,n,jump;
	double people,committee;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf",&people);
		committee=(sqrt(8*people+9)-1)/2;
		if(committee==floor(committee)){
			for(i=2;i<(int)committee;i++)
				printf("%d ",i);
			printf("%.0lf\n",committee);
		}
		else{
			n=(int)ceil(committee);
			if((n+2)*(n-1)/2==people+1){
				for(i=3;i<n;i++)
					printf("%d ",i);
				printf("%d\n",n+1);
			}
			else{
				jump=(n+2)*(n-1)/2-(int)people;
				for(i=2;i<n;i++)
					if(i!=jump)
						printf("%d ",i);
				printf("%d\n",n);
			}
		}
		if(cases) puts("");
	}
	return 0;
}
