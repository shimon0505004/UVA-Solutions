#include<stdio.h>
int main()
{
	int N,Q,i,temp,cases=0,j;
	int marble[10005],result;
	while(scanf("%d%d",&N,&Q)==2&&(N+Q)){
		memset(marble,0,sizeof(marble));
		printf("CASE# %d:\n",++cases);
		for(i=0;i<N;i++){
			scanf("%d",&temp);
			marble[temp]++;
		}
		for(i=0;i<Q;i++){
			scanf("%d",&temp);
			if(!marble[temp])
				printf("%d not found\n",temp);
			else{
				result=0;
				for(j=0;j<temp;j++)
					result+=marble[j];
				printf("%d found at %d\n",temp,result+1);
			}
		}
	}
	return 0;
}
