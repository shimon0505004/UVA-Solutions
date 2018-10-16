#include<stdio.h>
int r,c;
char rival(char RSP)
{
	switch(RSP){
		case 'R':
			return 'P';
		case 'P':
			return 'S';
		case 'S':
			return 'R';
		default:
			return '\0';
	}
}
void fight(char RSP[][105])
{
	char temp[105][105]={0};
	int i,j,k,m;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			for(k=-1;k<=1;k++)
				for(m=-1;m<=1;m++){
					if(abs(k+m)==1){
						if(RSP[i+k][j+m]==rival(RSP[i][j])){
							temp[i][j]=RSP[i+k][j+m];
							k=1;
							break;
						}
						else
							temp[i][j]=RSP[i][j];
					}
				}
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			RSP[i][j]=temp[i][j];
}
int main()
{
	char RSP[105][105];
	int n,i,j;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&r,&c,&n);
		memset(RSP,0,sizeof(RSP));
		for(i=1;i<=r;i++)
			scanf("%s",RSP[i]+1);
		while(n--)
			fight(RSP);
		for(i=1;i<=r;i++)
			printf("%s\n",RSP[i]+1);
		if(cases) printf("\n");
	}
	return 0;
}
