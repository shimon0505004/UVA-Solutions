#include<stdio.h>
#include<string.h>
const int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void count(char mines[][12],int n){
	int i,j,d;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(mines[i][j]=='*') continue;
			mines[i][j]='0';
			for(d=0;d<8;d++)
				if(mines[i+dir[d][0]][j+dir[d][1]]=='*')
					mines[i][j]++;
		}
}
int main(){
	int cases,n,i,j;
	char mines[12][12],isexplode;
	char detect[12][12];
	scanf("%d",&cases);
	while(cases--){
		memset(mines,0,sizeof(mines));
		isexplode=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%s",mines[i]+1);
		count(mines,n);
		for(i=1;i<=n;i++){
			scanf("%s",detect[i]+1);
			for(j=1;j<=n;j++){
				if(detect[i][j]=='.') continue;
				detect[i][j]=mines[i][j];
				if(mines[i][j]=='*') isexplode=1;
			}
		}
		if(isexplode){
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(mines[i][j]=='*') detect[i][j]='*';
		}
		for(i=1;i<=n;i++)
			puts(detect[i]+1);
		if(cases) puts("");
	}
	return 0;
}
