#include<stdio.h>
#include<string.h>
#define UBOUND 1000000
int main(){
	int unlimited[105];
	int coins[6]={1,2,4,10,20,40};
	int i,j;
	int limited[6][145];
	int used[145];
	int p1,p2,price;
	unlimited[0]=0;
	for(i=1;i<=100;i++)
		unlimited[i]=UBOUND;
	for(i=1;i<=100;i++)
		for(j=0;j<6;j++){
			if(coins[j]>i) continue;
			if(unlimited[i-coins[j]]+1<unlimited[i])
				unlimited[i]=unlimited[i-coins[j]]+1;
		}
	for(;;){
		int total=0,min,minj,max;
		for(i=0;i<=140;i++) used[i]=0;
		for(i=0;i<6;i++) scanf("%d",&limited[i][0]),total+=limited[i][0]*coins[i];
		if(total==0) break;
		scanf("%d%*c%d",&p1,&p2);
		price=p1*20+p2/5;
		max=total>price+40?price+40:total;
		for(i=1;i<=max;i++){
			min=UBOUND;
			for(j=0;j<6;j++){
				if(coins[j]>i||limited[j][i-coins[j]]==0) continue;
				if(used[i-coins[j]]+1<min) min=used[i-coins[j]]+1,minj=j;
			}
			used[i]=min;
			if(min<UBOUND){
				for(j=0;j<6;j++)
					limited[j][i]=limited[j][i-coins[minj]];
				limited[minj][i]--;
			}
		}
		min=UBOUND;
		for(i=price;i<=max;i++)
			if(used[i]+unlimited[i-price]<min)
				min=used[i]+unlimited[i-price];
		printf("%3d\n",min);
	}
	return 0;
}
