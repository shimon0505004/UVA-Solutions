#include<stdio.h>
void dfs(int a,int w,int h,int *count,int x,int y){
	int n;
	if(a==0) return;
	if(x>=(w-a)&&x<=(w+a)&&y>=h-a&&y<=h+a)
		(*count)++;
	n=a>>1;
	dfs(n,w-a,h-a,count,x,y);
	dfs(n,w-a,h+a,count,x,y);
	dfs(n,w+a,h-a,count,x,y);
	dfs(n,w+a,h+a,count,x,y);
}
int main()
{
	int k,x,y,count;
	while(scanf("%d%d%d",&k,&x,&y)==3&&k){
		count=0;
		dfs(k,1024,1024,&count,x,y);
		printf("%3d\n",count);
	}
	return 0;
}
