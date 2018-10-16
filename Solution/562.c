#include<stdio.h>
#include<string.h>
#define MAX 25005
int main(){
	int cases,m,i,j,coin,n,total,half,diff;
	char c[MAX];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&m);
		total=0;
		memset(c,0,sizeof(c));
		c[0]=1;
		for(i=0;i<m;i++){
			scanf("%d",&coin);
			j=total+1;
			if(j+coin>=MAX) j=MAX-coin;
			while(j--)
				if(c[j]) c[j+coin]=1;
			total+=coin;
		}
		for(half=total>>1;half>=0;half--){
			if(c[half]){
				diff=total-half*2;
				break;
			}
		}
		printf("%d\n",diff);
	}
	return 0;
}
