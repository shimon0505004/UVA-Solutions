#include<stdio.h>
#include<string.h>
int main()
{
	int m,i,j,a,b,n,flag;
	char node[205][205],color[205];
	while(scanf("%d",&n),n){
		scanf("%d",&m);
		memset(node,0,sizeof(node));
		memset(color,0,sizeof(color));
		while(m--){
			scanf("%d%d",&a,&b);
			node[a][b]=node[b][a]=1;
		}
		flag=1;
		color[0]=1;
		for(i=0;i<n&&flag;i++)
			for(j=0;j<n&&flag;j++)
				if(node[i][j])
					if(!color[j])
						color[j]=3-color[i];
					else if(color[j]==color[i]){
						flag=0;
						break;
					}
		if(!flag) puts("NOT BICOLORABLE.");
		else puts("BICOLORABLE.");
	}
	return 0;
}
