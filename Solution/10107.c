#include<stdio.h>
int main()
{
	int nums[10100]={0};
	int i=0,j,k;
	while(scanf("%d",&nums[i])!=EOF){
		for(j=0;j<=i;j++)
			if(nums[j]>nums[i]){
				for(k=i;k>=j;k--)
					nums[k+1]=nums[k];
				nums[j]=nums[i+1];
				break;
			}
		if(i%2==0)
			printf("%d\n",nums[i/2]);
		else
			printf("%d\n",(nums[i/2]+nums[i/2+1])/2);
		i++;	
	}
	return 0;
}
