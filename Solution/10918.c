#include<stdio.h>
int main()
{
	int n,i;
	int tiling[31][2]={0};
	tiling[0][0]=1,tiling[0][1]=0;
	for(i=2;i<=30;i+=2){
		tiling[i][0]=tiling[i-2][0]*3+tiling[i-2][1];
		tiling[i][1]=tiling[i-2][0]*2+tiling[i-2][1];
	}
	while(scanf("%d",&n),n>=0)
		printf("%d\n",tiling[n][0]);
	return 0;
}
