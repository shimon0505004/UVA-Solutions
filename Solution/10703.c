#include<stdio.h>
#include<string.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b,*b=temp;
}
int main()
{
	char map[505][505];
	int W,H,N,lx,dy,rx,uy,i,j,tot;
	while(scanf("%d%d%d",&W,&H,&N)==3&&(W+H+N)){
		memset(map,1,sizeof(map));
		while(N--){
			scanf("%d%d%d%d",&lx,&dy,&rx,&uy);
			if(lx>rx) swap(&lx,&rx);
			if(dy>uy) swap(&dy,&uy);
			for(i=lx;i<=rx;i++)
				for(j=dy;j<=uy;j++)
					map[i][j]=0;
		}
		tot=0;
		for(i=1;i<=W;i++)
			for(j=1;j<=H;j++)
				tot+=map[i][j];
		if(!tot)
			puts("There is no empty spots.");
		else if(tot==1)
			puts("There is one empty spot.");
		else
			printf("There are %d empty spots.\n",tot);
	}
	return 0;
}
