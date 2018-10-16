#include<stdio.h>
#include<string.h>
#define max 100000
int main()
{
	int cases,i,n,j;
	int ranks[max];
	char nums[max][15];
	char inputrank[max],*tokenPtr;
	scanf("%d ",&cases);
	for(i=0;i<cases;i++){
		if(i) printf("\n");
		memset(nums,0,sizeof(nums));
		fgets(inputrank,max,stdin);
		tokenPtr=strtok(inputrank," ");
		n=0;
		memset(ranks,0,sizeof(ranks));
		while(tokenPtr!=NULL){
			sscanf(tokenPtr,"%d",&ranks[n++]);
			tokenPtr=strtok(NULL," ");
		}
		for(j=0;j<n;j++)
			scanf("%s",nums[ranks[j]-1]);
		for(j=0;j<n;j++)
			printf("%s\n",nums[j]);
		scanf(" ");
	}
	return 0;
}
