#include<stdio.h>
int main()
{
	int cases,i,a,b,j,tot,n=0;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d%d",&a,&b);
		for(j=a,tot=0;j<=b;j++){
			if(j%2)
				tot+=j;
		}
		printf("Case %d: %d\n",++n,tot);
	}
	return 0;
}
