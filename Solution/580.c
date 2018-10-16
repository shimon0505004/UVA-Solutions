#include<stdio.h>
int main(){
	int danger[31]={0,0,0,1},i,n;
	for(i=4;i<31;i++)
		danger[i]=(danger[i-1]<<1)+((1<<(i-4))-danger[i-4]);
	while(scanf("%d",&n),n)
		printf("%d\n",danger[n]);
	return 0;
}
