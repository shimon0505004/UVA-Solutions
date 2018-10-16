#include<stdio.h>
void findmine(char[][120],int,int);
int H,W;
int main()
{
	int i,j,n=1;
	char mine[120][120];
	while(1){
		scanf("%d%d",&H,&W);
		getchar();
		if(W+H==0) break;
		if(n>1) printf("\n");
		for(i=0;i<H;i++){
			for(j=0;j<W;j++)
				scanf("%c",&mine[i][j]);
			getchar();
		}
		for(i=0;i<H;i++)
			for(j=0;j<W;j++)
				if(mine[i][j]!='*')
					findmine(mine,i,j);
		printf("Field #%d:\n",n);
		for(i=0;i<H;i++){
			for(j=0;j<W;j++)
				printf("%c",mine[i][j]);
			printf("\n");
		}
		n++;		
	}
	return 0;
}
void findmine(char mine[][120],int h,int w)
{
	int i,j,tot=0;	
	for(i=-1;i<2;i++){
		if(h+i<0 || h+i>=H)
			continue;
		for(j=-1;j<2;j++){
			if(i==0 && j==0) 
				continue;
			else if(w+j<0 || w+j>=W)
				continue;
			else if(mine[h+i][w+j]=='*')
				tot++;
		}
	}
	mine[h][w]=tot+'0';
}
