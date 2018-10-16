#include<stdio.h>
int main()
{
	int i,j,k,l,max;
	int N,cases;
	char num[30][30];
	int map[30][30];
	scanf("%d",&cases);
	while(cases--){
		memset(num,0,sizeof(num));
		scanf("%s",num[1]+1);
		N=strlen(num[1]+1);
		for(i=2;i<=N;i++)
			scanf("%s",num[i]+1);
		memset(map,0,sizeof(map));
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++){
				map[i][j]=num[i][j]-'0'?0:1;
				map[i][j]+=map[i-1][j];
			}
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				map[i][j]+=map[i][j-1];
		max=0;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				for(l=0;l<i;l++)
					for(k=0;k<j;k++)
						if(!(map[i][j]-map[i][k]-map[l][j]+map[l][k]))
							if((i-l)*(j-k)>max)
								max=(i-l)*(j-k);
		printf("%d\n",max);
		if(cases) puts("");
	}
	return 0;
}
