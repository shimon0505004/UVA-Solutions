#include<stdio.h>
#include<string.h>
int main(){
	int T,R,H,i,j,k;
	signed char tT[20][20],tR[20][20],tH[20][20];
	int pT[20],pR[20],pH[20];
	int aT,aR,aH,price;
	while(scanf("%d%d%d",&T,&R,&H)==3){
		memset(tT,0,sizeof(tT));
		memset(tR,0,sizeof(tR));
		memset(tH,0,sizeof(tH));
		for(i=0;i<T;i++){
			scanf("%d",&pT[i]);
			for(j=0;j<R;j++)
				scanf("%hhd",&tT[i][j]);
		}
		for(i=0;i<R;i++){
			scanf("%d",&pR[i]);
			for(j=0;j<H;j++)
				scanf("%hhd",&tR[i][j]);
		}
		for(i=0;i<H;i++){
			scanf("%d",&pH[i]);
			for(j=0;j<T;j++)
				scanf("%hhd",&tH[i][j]);
		}
		price=2147483647;
		for(i=0;i<T;i++)
			for(j=0;j<R;j++){
				if(tT[i][j]==1) continue;
				for(k=0;k<H;k++){
					if(tR[j][k]==1||tH[k][i]==1) continue;
					if(price>pT[i]+pR[j]+pH[k]){
						price=pT[i]+pR[j]+pH[k];
						aT=i,aR=j,aH=k;
					}
				}
			}
		if(price==2147483647) puts("Don't get married!");
		else printf("%d %d %d:%d\n",aT,aR,aH,price);
	}
	return 0;
}
