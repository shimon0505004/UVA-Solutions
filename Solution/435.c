#include<stdio.h>
#include<string.h>
int main(){
	int N,P;
	int vote[21];
	int table[1005],n_vote,half_vote;
	int nowP,i,j;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&P);
		n_vote=0;
		for(i=1;i<=P;i++) scanf("%d",&vote[i]),n_vote+=vote[i];
		half_vote=n_vote/2;
		for(nowP=1;nowP<=P;nowP++){
			int temp,p_index=0;
			memset(table,0,sizeof(table));
			table[0]=1;
			temp=vote[nowP],vote[nowP]=vote[1],vote[1]=temp;
			for(i=2;i<=P;i++)
				for(j=half_vote-vote[i];j>=0;j--)
					table[j+vote[i]]+=table[j];
			for(i=half_vote-vote[1]+1;i<=half_vote;i++)
				p_index+=table[i];
			printf("party %d has power index %d\n",nowP,p_index);
		}
		puts("");
	}
	return 0;
}
