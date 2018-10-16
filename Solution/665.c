#include<stdio.h>
#include<string.h>
#define IMPOSSIBLE -1
#define UNKNOWN 0
#define LIGHT 1
#define HEAVY 2
#define LEFT -1
#define RIGHT 1
int main(){
	int cases,i,N,K,count;
	char coin[105],LR[105];
	int balance,n_unknown,n_false,falsecoin,unknowncoin,n;
	scanf("%d",&cases);
	while(cases--){
		memset(coin,UNKNOWN,sizeof(coin));
		scanf("%d%d",&N,&K);
		while(K--){
			memset(LR,0,sizeof(LR));
			scanf("%d",&count);
			for(i=0;i<count;i++) scanf("%d",&n),LR[n]=LEFT;
			for(i=0;i<count;i++) scanf("%d",&n),LR[n]=RIGHT;
			scanf(" %c",&balance);
			if(balance=='>')
				for(i=1;i<=N;i++){
					if(LR[i]==LEFT){
						if(coin[i]==UNKNOWN) coin[i]=HEAVY;
						else if(coin[i]==LIGHT) coin[i]=IMPOSSIBLE;
					}else if(LR[i]==RIGHT){
						if(coin[i]==UNKNOWN) coin[i]=LIGHT;
						else if(coin[i]==HEAVY) coin[i]=IMPOSSIBLE;
					}else if(coin[i]!=UNKNOWN) coin[i]=IMPOSSIBLE;
				}
			else if(balance=='<')
				for(i=1;i<=N;i++){
					if(LR[i]==LEFT){
						if(coin[i]==UNKNOWN) coin[i]=LIGHT;
						else if(coin[i]==HEAVY) coin[i]=IMPOSSIBLE;
					}else if(LR[i]==RIGHT){
						if(coin[i]==UNKNOWN) coin[i]=HEAVY;
						else if(coin[i]==LIGHT) coin[i]=IMPOSSIBLE;
					}else if(coin[i]!=UNKNOWN) coin[i]=IMPOSSIBLE;
				}
			else
				for(i=1;i<=N;i++) if(LR[i]) coin[i]=IMPOSSIBLE;
		}
		n_false=n_unknown=0;
		for(i=1;i<=N;i++)
			if(coin[i]==LIGHT||coin[i]==HEAVY) falsecoin=i,n_false++;
			else if(coin[i]==UNKNOWN) unknowncoin=i,n_unknown++;
		if(n_false==1) printf("%d\n",falsecoin);
		else if(n_false==0&&n_unknown==1) printf("%d\n",unknowncoin);
		else puts("0");
		if(cases) puts("");
	}
	return 0;
}
