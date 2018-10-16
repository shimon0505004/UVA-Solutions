#include<stdio.h>
int main()
{
	int i,j,n,num[101][101]={0},k,l,a,b,max,tot,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&num[i][j]);
			num[i][j]+=num[i-1][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			num[j][i]+=num[j][i-1];
	max=num[0][0];
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			for(k=0;k<j;k++)
				for(l=0;l<i;l++){
					temp=(num[i][j]-num[i][k]-num[l][j]+num[l][k]);
					if(temp>max)
						max=temp;
				}
	printf("%d\n",max);
	return 0;
}
