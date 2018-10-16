#include<stdio.h>
#include<string.h>
#include<ctype.h>
int w,h;
int add[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char search(char *test,char map[][55],int y,int x)
{
	int i,len,dir,tempx,tempy;
	len=strlen(test);
	for(dir=0;dir<8;dir++){
		tempx=x;
		tempy=y;
		for(i=1;i<len;i++){
			tempx+=add[dir][0];
			if(tempx<0||tempx>=w) break;
			tempy+=add[dir][1];
			if(tempy<0||tempy>=h) break;
			if(tolower(map[tempy][tempx])!=tolower(test[i])) break;
		}
		if(i==len) return 1;
	}
	return 0;
}
int main()
{
	int cases,tcases;
	int i,j;
	char map[55][55];
	char test[55];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&h,&w);
		for(i=0;i<h;i++)
			scanf("%s",map[i]);
		scanf("%d",&tcases);
		while(tcases--){
			scanf("%s",test);
			for(i=0;i<h;i++)
				for(j=0;j<w;j++)
					if(tolower(map[i][j])==tolower(*test))
						if(search(test,map,i,j)){
							printf("%d %d\n",i+1,j+1);
							j=w,i=h;
						}
		}
		if(cases) puts("");
	}
	return 0;
}
