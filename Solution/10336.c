#include<stdio.h>
#include<string.h>
#include<ctype.h>
char language[26];
char world[105][105];
char dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
void transfer(int row,int col,char kind)
{
	int i;
	for(i=0;i<4;i++)
		if(world[row+dir[i][0]][col+dir[i][1]]==kind){
			world[row+dir[i][0]][col+dir[i][1]]='*';
			transfer(row+dir[i][0],col+dir[i][1],kind);
		}
}
int main()
{
	int m,n,i,j,cases,count=0,max,maxi;
	scanf("%d",&cases);
	while(count<cases){
		scanf("%d%d",&m,&n);
		memset(world,'*',sizeof(world));
		memset(language,0,sizeof(language));
		for(i=1;i<=m;i++)
			scanf("%s",world[i]+1);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(isalpha(world[i][j])){
					language[world[i][j]-'a']++;
					transfer(i,j,world[i][j]);
				}
		printf("World #%d\n",++count);
		do{
			max=-1;
			for(i=0;i<26;i++)
				if(language[i]>max){
					max=language[i];
					maxi=i;
				}
			if(max){
				printf("%c: %d\n",maxi+'a',language[maxi]);
				language[maxi]=0;
			}
		}while(max);
	}
	return 0;
}
