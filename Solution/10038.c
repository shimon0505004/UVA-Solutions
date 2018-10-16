#include<stdio.h>
#define NJ 1
#define OK 0
int main()
{
	long nums[3005],diff[3005];
	int i,j,n,tot,flag=OK;
	char temp[6000];
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			gets(temp);
			printf("Jolly\n");
			continue;
		}
		else if(n<=0){
			gets(temp);
			printf("Not jolly\n");
			continue;
		}
		for(i=0;i<n;i++)
			scanf("%d",&nums[i]);
		if(n==2 && (nums[0]-nums[1])*((nums[0]-nums[1])<0?-1:1)==1){
			printf("Jolly\n");
			continue;
		}
		flag=OK;
		tot=0;
		for(i=0;i<n-1 && flag==OK;i++){
			diff[i]=(nums[i+1]-nums[i])*((nums[i+1]-nums[i])<0?-1:1);
			tot+=diff[i];
			if(diff[i]>=n||diff[i]<=0){
				printf("Not jolly\n");
				flag=NJ;
			}
		}
		if(tot!=n*(n-1)/2 && flag==OK){
			printf("Not jolly\n");
			continue;
		}
		for(i=0;i<n-1 && flag==OK;i++)
			for(j=i+1;j<n && flag==OK;j++)
				if(diff[i]==diff[j]){
					printf("Not jolly\n");
					flag=NJ;
				}
		if(flag==OK)
			printf("Jolly\n");
	}
	return 0;
}


