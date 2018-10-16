#include<stdio.h>
#include<string.h>
int s;
int add[9][2]={{0,0},{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char search(char *test,char map[][105],int y,int x)
{
	int i,len,dir,tempx,tempy;
	len=strlen(test);
	for(dir=1;dir<=8;dir++){
		tempx=x;
		tempy=y;
		for(i=1;i<len;i++){
			tempx+=add[dir][0];
			if(tempx<0||tempx>=s) break;
			tempy+=add[dir][1];
			if(tempy<0||tempy>=s) break;
			if(map[tempy][tempx]!=test[i]) break;
		}
		if(i==len) return dir;
	}
	return 0;
}
int main()
{
	int i,j,flag,dir,len;
	char map[105][105];
	char test[105];
	scanf("%d",&s);
	while(1){
		if(!s) break;
		for(i=0;i<s;i++)
			scanf("%s ",map[i]);
		while(1){
			fgets(test,105,stdin);
			if(sscanf(test,"%d",&s)==1) break;
			test[strlen(test)-1]=0;
			len=strlen(test),flag=1;
			for(i=0;i<s&&flag;i++)
				for(j=0;j<s&&flag;j++)
					if(map[i][j]==*test)
						if(dir=search(test,map,i,j)){
							printf("%d,%d %d,%d\n",i+1,j+1,i+1+add[dir][1]*(len-1),j+1+add[dir][0]*(len-1));
							flag=0;
						}
			if(i==s&&j==s) puts("Not found");
		}
	}
	return 0;
}
