#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi (2*acos(0))
int main()
{
	int cases,n,infor[2];
	char input[10],*tokenPtr;
	double result;
	scanf("%d ",&cases);
	while(cases--){
		fgets(input,10,stdin);
		n=0;
		for(tokenPtr=strtok(input," ");tokenPtr!=NULL;tokenPtr=strtok(NULL," "))
			infor[n++]=atoi(tokenPtr);
		if(n==2)
			result=2.0*infor[0]*infor[1]*pi;
		else
			result=(double)infor[0]*infor[0]/8.0*pi;
		printf("%.4lf\n",result);


	}
	return 0;
}
