#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int cases,n_B,SG,SB,i,n_fight,now;
	int G[105],B[105],tmp,rG[100005],rB[100005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&n_B,&SG,&SB);
		memset(G,0,sizeof(G)),memset(B,0,sizeof(B));
		for(i=0;i<SG;i++)
			scanf("%d",&tmp),G[tmp]++;
		for(i=0;i<SB;i++)
			scanf("%d",&tmp),B[tmp]++;
		while(SG>0&&SB>0){
			n_fight=MIN(MIN(SG,SB),n_B);
			for(i=100,now=0;now<n_fight;i--)
				for(;G[i]>0&&now<n_fight;G[i]--,now++)
					rG[now]=i;
			for(i=100,now=0;now<n_fight;i--)
				for(;B[i]>0&&now<n_fight;B[i]--,now++)
					rB[now]=i;
			for(i=0;i<n_fight;i++){
				if(rG[i]>rB[i]) rG[i]=rG[i]-rB[i],rB[i]=0;
				else rB[i]=rB[i]-rG[i],rG[i]=0;
			}
			for(i=0;i<n_fight;i++){
				if(rG[i]>0) G[rG[i]]++;
				else SG--;
				if(rB[i]>0) B[rB[i]]++;
				else SB--;
			}
		}
		if(SG==0&&SB==0) puts("green and blue died");
		else if(SG>0){
			puts("green wins");
			for(i=100;i>0;i--)
				for(;G[i]>0;G[i]--)
					printf("%d\n",i);
		}else if(SB>0){
			puts("blue wins");
			for(i=100;i>0;i--)
				for(;B[i]>0;B[i]--)
					printf("%d\n",i);
		}
		if(cases) puts("");
	}
	return 0;
}
