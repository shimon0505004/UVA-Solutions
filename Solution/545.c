#include<stdio.h>
#include<math.h>
#define log2 log10(2)
int main()
{
	double result,n,head;
	char input[10];
	int cases;
	scanf("%d ",&cases);
	while(1){
		memset(input,0,sizeof(input));
		if(fgets(input,10,stdin)==NULL) break;
		if(*input=='\n'){
			printf("\n");
			continue;
		}
		n=atoi(input);
		n*=-1;
		head=floor(n*log2);
		if(n==-7)
			printf("2^-7 = 7.813E-3\n");
		else if(n==-6)
			printf("2^-6 = 1.563E-2\n");
		else
			printf("2^%.0lf = %.3lfE%.0lf\n",n,pow(10,n*log2-head),head);
	}
	return 0;
}
