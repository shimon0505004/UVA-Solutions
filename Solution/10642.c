#include<stdio.h>
int count(int x,int y)
{
	int n=x+y;
	n=n*(n+1)/2;
	return x+n+1;
}
int main()
{
	int cases,i,x1,y1,x2,y2;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		printf("Case %d: ",i+1);
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",count(x2,y2)-count(x1,y1));
	}
	return 0;
}
