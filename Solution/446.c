#include<stdio.h>
int main()
{
	int i,j,n,n1,n2,test,result;
	char opera[2];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		memset(opera,0,sizeof(opera));
		scanf("%X%s%X",&n1,opera,&n2);
		for(j=0,test=1<<12;j<13;j++){
			printf("%d",(test & n1?1:0));
			test>>=1;
		}
		printf(" %c ",opera[0]);
		for(j=0,test=1<<12;j<13;j++){
			printf("%d",(test & n2?1:0));
			test>>=1;
		}
		if(opera[0]=='+')
			result=n1+n2;
		else
			result=n1-n2;
		printf(" = %d\n",result);
	}
	return 0;
}
