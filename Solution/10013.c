#include<stdio.h>
#include<string.h>
int main()
{
	int cases,i,j,digits;
	int num1,num2;
	char result[1000002];
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		memset(result,0,sizeof(result));
		scanf("%d",&digits);
		for(j=0;j<digits;j++){
			scanf("%d%d",&num1,&num2);
			result[j]=num1+num2;
		}
		for(j=digits;j>0;j--){
			result[j-1]+=result[j]/10;
			result[j]%=10;
		}
		result[0]%=10;
		for(j=0;j<digits;j++)
			result[j]+='0';
		printf("%s\n",result);
		if(i<cases-1) printf("\n");
	}
	return 0;
}
