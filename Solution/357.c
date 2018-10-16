#include<stdio.h>
#define max 30000
int main()
{
	long long count[max+1]={0},i,j,n,faces[5]={1,5,10,25,50};
	count[0]=1;
	for(i=0;i<5;i++)
		for(j=faces[i];j<=max;j++)
			count[j]+=count[j-faces[i]];
	while(scanf("%lld",&n)==1){
		if(count[n]-1)
			printf("There are %lld ways to produce %lld cents change.\n",count[n],n);
		else
			printf("There is only 1 way to produce %lld cents change.\n",n);
	}
	return 0;
}
