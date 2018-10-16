#include<stdio.h>
#define max 6000
int main()
{
	long long int count[max+1]={0},i,j,faces[11]={1,2,4,10,20,40,100,200,400,1000,2000};
	double n;
	int temp;
	count[0]=1;
	for(i=0;i<11;i++)
		for(j=faces[i];j<=max;j++)
			count[j]+=count[j-faces[i]];
	while(scanf("%lf",&n)==1){
		if(n==0.00) break;
		temp=(n*100+0.5);
		temp/=5;
		printf("%6.2lf%17lld\n",n,count[temp]);
	}
	return 0;
}
