#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int cases,K;
	int NS[100],WE[100];
	char look[100];
	int max,min;
	int i,j;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&K);
		for(i=0;i<K;i++) scanf("%d",&NS[i]);
		for(i=0;i<K;i++) scanf("%d",&WE[i]);
		max=min=0;
		memset(look,0,sizeof(look));
		for(i=0;i<K;i++){
			for(j=0;j<K;j++){
				if(NS[i]==WE[j]&&look[j]==0){
					look[j]=1;
					break;
				}
			}
			min+=NS[i];
		}
		for(i=0;i<K;i++)
			if(look[i]==0) min+=WE[i];
		for(i=0;i<K;i++)
			for(j=0;j<K;j++)
				max+=MIN(NS[i],WE[j]);
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",
				min,max-min);
	}
	return 0;
}
