#include<stdio.h>
#include<string.h>
int main(){
	int C,S,E,T,i,j,k;
	int table[1000][105];
	int earn[105][105];
	int max;
	while(scanf("%d%d%d%d",&C,&S,&E,&T),C+S+E+T){
		for(i=1;i<=C;i++)
			for(j=1;j<=C;j++)
				scanf("%d",&earn[i][j]);
		memset(table,0,sizeof(table));
		for(i=1;i<=C;i++) table[1][i]=earn[S][i];
		for(i=2;i<=T;i++)
			for(j=1;j<=C;j++){
				max=0;
				for(k=1;k<=C;k++)
					if(table[i-1][k]+earn[k][j]>max)
						max=table[i-1][k]+earn[k][j];
				table[i][j]=max;
			}
		max=0;
		for(i=0;i<E;i++){
			int end;
			scanf("%d",&end);
			if(table[T][end]>max) max=table[T][end];
		}
		printf("%d\n",max);
	}
	return 0;
}
