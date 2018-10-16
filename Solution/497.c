#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Ubound 1005
int max,maxj;
int missile[Ubound];
int predecessor[Ubound];
int n;
int FindLIS()
{
	int length[Ubound];
	int i,j;
	max=1,maxj=0;
	for(i=0;i<n;i++){
		predecessor[i]=-1;
		length[i]=1;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(missile[j]>missile[i])
				if(length[i]>=length[j]){
					length[j]=length[i]+1;
					if(length[j]>max){
						max=length[j];
						maxj=j;
					}
					predecessor[j]=i;
				}
	return max;
}
void printLIS(int current)
{
	if(current<0) return;
	printLIS(predecessor[current]);
	printf("%d\n",missile[current]);
}
int main()
{
	int cases,i,count;
	char temp[20];
	scanf("%d ",&cases);
	for(count=0;count<cases;count++){
		if(count) printf("\n");
		for(n=0;;n++){
			fgets(temp,20,stdin);
			if(feof(stdin)) break;
			if(*temp=='\n') break;
			missile[n]=atoi(temp);
		}
		memset(predecessor,0,sizeof(predecessor));
		printf("Max hits: %d\n",FindLIS());
		printLIS(maxj);
	}
	return 0;
}
