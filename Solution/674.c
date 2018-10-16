#include<stdio.h>
#define max 7500
int main()
{
	int count[max+1]={0},i,j,n,faces[5]={1,5,10,25,50};
	count[0]=1;
	for(i=0;i<5;i++)
		for(j=faces[i];j<=max;j++)
			count[j]+=count[j-faces[i]];
	while(scanf("%d",&n)==1)
		printf("%d\n",count[n]);
	return 0;
}
