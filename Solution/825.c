#include<stdio.h>
#include<string.h>
int main()
{
	int Road[105][105];
	int cases;
	int W,N;
	int dangerW,i,j,count;
	char danger[1000],*tokenPtr;
	scanf("%d",&cases);
	for(count=0;count<cases;count++){
		if(count) printf("\n");
		scanf("%d%d",&W,&N);
		memset(Road,0,sizeof(Road));
		for(i=0;i<W;i++){
			scanf("%d",&dangerW);
			fgets(danger,1000,stdin);
			for(tokenPtr=strtok(danger," ");tokenPtr!=NULL;tokenPtr=strtok(NULL," "))
				Road[dangerW][atoi(tokenPtr)]=-1;
		}
		Road[1][1]=1;
		for(i=1;i<=W;i++)
			for(j=1;j<=N;j++)
				if(Road[i][j]>=0){
					Road[i][j]+=(Road[i-1][j]<0?0:Road[i-1][j]);
					Road[i][j]+=(Road[i][j-1]<0?0:Road[i][j-1]);
				}
		printf("%d\n",Road[W][N]);
	}
	return 0;
}
