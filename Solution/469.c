#include<stdio.h>
#include<string.h>
int find(char Florida[][105],int row,int col)
{
	int i,j,result=1;
	Florida[row][col]='L';
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++)
			if(Florida[row+i][col+j]=='W')
				result+=find(Florida,row+i,col+j);
	return result;
}
int main()
{
	char Florida[105][105],temp[105][105];
	char input[105];
	int wetland,cases,n,i,j;
	scanf("%d",&cases);
	while(cases--){
		memset(Florida,0,sizeof(Florida));
		scanf(" ");
		for(n=1;fgets(Florida[n]+1,105,stdin),Florida[n][1]=='L'||Florida[n][1]=='W';n++);
		sscanf(Florida[n]+1,"%d%d",&i,&j);
		memcpy(temp,Florida,sizeof(Florida));
		printf("%d\n",find(temp,i,j));
		while(fgets(input,105,stdin)!=NULL&&*input!='\n'){
			sscanf(input,"%d%d",&i,&j);
			memcpy(temp,Florida,sizeof(Florida));
			printf("%d\n",find(temp,i,j));
		}
		if(cases) puts("");
	}
	return 0;
}
