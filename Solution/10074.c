#include<stdio.h>
int main()
{
	int i,j,num[101][101],k,l,max;
	int x,y;
	while(scanf("%d%d",&y,&x)==2&&(x+y)){
		memset(num,0,sizeof(num));
		for(i=1;i<=y;i++)
			for(j=1;j<=x;j++){
				scanf("%d",&num[i][j]);
				num[i][j]+=num[i-1][j];
			}
		for(i=1;i<=y;i++)
			for(j=1;j<=x;j++)
				num[i][j]+=num[i][j-1];
		max=0;
		for(i=1;i<=y;i++)
			for(j=1;j<=x;j++)
				for(l=0;l<i;l++)
					for(k=0;k<j;k++)
						if(!(num[i][j]-num[i][k]-num[l][j]+num[l][k]))
							if((i-l)*(j-k)>max)
								max=(i-l)*(j-k);
		printf("%d\n",max);
	}
	return 0;
}
