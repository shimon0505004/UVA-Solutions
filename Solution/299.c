#include<stdio.h>
int main()
{
	int i,j,k,times,n,temp,num[55],count;
	scanf("%d",&times);
	for(i=0;i<times;i++){
		count=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&num[j]);
		for(j=0;j<n-1;j++)
			for(k=0;k<n-j-1;k++)
				if(num[k]>num[k+1]){
					count++;
					temp=num[k];
					num[k]=num[k+1];
					num[k+1]=temp;
				}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
	return 0;
}
