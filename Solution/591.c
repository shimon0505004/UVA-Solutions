#include<stdio.h>
int main()
{
	int i,n,average,block[50],times=1,moves;
	while(1){
		average=0;
		moves=0;
		for(i=0;i<50;i++)
			block[i]=0;
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%d",&block[i]);
			average+=block[i];
		}
		average/=n;
		for(i=0;i<n;i++)
			moves+=(block[i]-average)*(block[i]-average<0?(-1):1);
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",times,moves/2);
		times++;
	}
	return 0;
}
