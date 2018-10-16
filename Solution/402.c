#include<stdio.h>
#include<string.h>
int main()
{
	int N,X,i,card[20],people[51],cases=0,rest,j,k,n=0;
	while(scanf("%d%d",&N,&X)==2){
		memset(card,0,sizeof(card));
		for(i=0;i<N;i++)
			people[i]=i;
		for(i=0;i<20;i++)
			scanf("%d",&card[i]);
		rest=N;
		for(i=0;i<20&&rest>X;i++)
			for(j=card[i];j<=rest&&rest>X;j+=(card[i]-1)){
				memmove(people+j-1,people+j,(rest-j)*sizeof(int));
				rest--;
			}
		printf("Selection #%d\n",++n);
		for(i=0;i<rest;i++){
			if(i) printf(" ");
			printf("%d",people[i]+1);
		}
		printf("\n\n");
	}
	return 0;
}
