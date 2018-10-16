#include<stdio.h>
#include<string.h>
void find(char map[][105],int row,int col)
{
	int i,j;
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++)
			if(map[row+i][col+j]=='1'){
				map[row+i][col+j]='0';
				find(map,row+i,col+j);
			}
}
int main()
{
	int s,i,j;
	char map[105][105];
	int eagle,cases=0;
	while(scanf("%d",&s)==1){
		memset(map,'0',sizeof(map));
		eagle=0;
		for(i=1;i<=s;i++)
			scanf("%s",map[i]+1);
		for(i=1;i<=s;i++)
			for(j=1;j<=s;j++)
				if(map[i][j]=='1'){
					find(map,i,j);
					eagle++;
				}
		printf("Image number %d contains %d war eagles.\n",++cases,eagle);
	}
	return 0;
}
