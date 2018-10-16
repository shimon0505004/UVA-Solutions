#include<stdio.h>
int main()
{
	int rank[7030]={0},count[32767]={0},*countPtr;
	int n,r=0,i;
	countPtr=count+16000;
	while(scanf("%d",&n)==1){
		if(!countPtr[n])
			rank[r++]=n;
		countPtr[n]++;
	}
	for(i=0;i<r;i++)
		printf("%d %d\n",rank[i],countPtr[rank[i]]);
	return 0;
}
