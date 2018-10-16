#include<stdio.h>
int main()
{
	int farmers[30],n,i,noffarm,j,EPV[30],animals;
	long prize;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		prize=0;
		scanf("%d",&noffarm);
		for(j=0;j<noffarm;j++)
			scanf("%d%d%d",&farmers[j],&animals,&EPV[j]);
		for(j=0;j<noffarm;j++)
			prize+=farmers[j]*EPV[j];
		printf("%d\n",prize);
	}
	return 0;
}
