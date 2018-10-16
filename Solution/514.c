#include<stdio.h>
int main()
{
	int N[1001],Pos[1001];
	int rails,i,exit,j,No;
	while(scanf("%d",&rails)==1&&rails){
		exit=0;
		while(!exit){
			for(i=1;i<=rails;i++){
				scanf("%d",&N[i]);
				if(!N[i]){
					exit=1;
					break;
				}
				Pos[N[i]]=i;
			}
			if(exit) break;
			No=0;
			for(i=rails;i>=1;i--){
				No=0;
				if(Pos[i-1]>Pos[i])
					for(j=Pos[i]+1;j<Pos[i-1];j++){
						if(N[j]<i){
							No=1;
							break;
						}
					}
				if(No) break;
			}
			if(No)
				printf("No\n");
			else
				printf("Yes\n");
		}
		printf("\n");
	}
	return 0;
}
