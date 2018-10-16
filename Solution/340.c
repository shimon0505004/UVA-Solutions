#include<stdio.h>
int main()
{
	int len,question[1000],temp[1000],guess[1000],i,j,exit,A,B,n=0;
	while(1){
		scanf("%d",&len);
		if(!len) break;
		for(i=0;i<len;i++)
			scanf("%d",&question[i]);
		printf("Game %d:\n",++n);
		while(1){
			exit=0;
			for(i=0;i<len;i++){
				scanf("%d",&guess[i]);
				exit+=guess[i];
			}
			if(!exit) break;
			A=B=0;
			for(i=0;i<len;i++)
				temp[i]=question[i];
			for(i=0;i<len;i++)
				if(temp[i]==guess[i]){
					A++;
					guess[i]=temp[i]=-1;
				}
			for(i=0;i<len;i++){
				if(temp[i]==-1) continue;
				for(j=0;j<len;j++){
					if(guess[j]==-1) continue;
					if(temp[i]==guess[j]){
						B++;
						guess[j]=-1;
						break;
					}
				}
			}
						
			printf("    (%d,%d)\n",A,B);
		}
	}
	return 0;
}
