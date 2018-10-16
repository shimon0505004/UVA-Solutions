#include<stdio.h>
void transfer(char oil[][105],int row,int col)
{
	int i,j;
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++)
			if(oil[row+i][col+j]=='@'){
				oil[row+i][col+j]='*';
				transfer(oil,row+i,col+j);
			}
}
int main()
{
	int m,n,i,j;
	char oil[105][105];
	int deposit;
	while(scanf("%d%d",&m,&n)&&(m+n)){
		memset(oil,'*',sizeof(oil));
		deposit=0;
		for(i=1;i<=m;i++)
			scanf("%s",oil[i]+1);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(oil[i][j]=='@'){
					transfer(oil,i,j);
					deposit++;
				}
		printf("%d\n",deposit);
	}
	return 0;
}
