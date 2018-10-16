#include<stdio.h>
int main(){
	int n,m,i,j,cases=0,query,diff,sum,t;
	int input[1005];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++) scanf("%d",&input[i]);
		printf("Case %d:\n",++cases);
		scanf("%d",&m);
		while(m--){
			scanf("%d",&query);
			diff=abs(query-input[0]-input[1]);
			sum=input[0]+input[1];
			for(i=0;i<n;i++)
				for(j=0;j<i;j++)
					if((t=abs(query-input[i]-input[j]))<diff)
						diff=t,sum=input[i]+input[j];
			printf("Closest sum to %d is %d.\n",query,sum);
		}
	}
	return 0;
}
