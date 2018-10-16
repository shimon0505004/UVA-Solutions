#include<stdio.h>
#include<string.h>
int main(){
	int h,w,i,j,k,l,t,recs;
	int map[105][105];
	while(scanf("%d%d",&h,&w)==2){
		memset(map,0,sizeof(map));
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++){
				scanf("%1d",&map[i][j]);
				map[i][j]+=map[i-1][j];
			}
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
				map[i][j]+=map[i][j-1];
		recs=0;
		for(i=0;i<=h;i++)
			for(j=0;j<=w;j++)
				for(k=0;k<i;k++)
					for(l=0;l<j;l++){
						if((t=map[i][j]-map[k][j]-map[i][l]+map[k][l])==(i-k)*(j-l))
							recs++;
					}
		printf("%d\n",recs);
	}
	return 0;
}
