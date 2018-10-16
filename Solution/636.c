#include<stdio.h>
#include<math.h>
int minbase(char num[]){
	int len=strlen(num),i;
	int min=1;
	for(i=0;i<len;i++)
		if(num[i]-'0'>min)
			min=num[i]-'0';
	return min+1;
}
int main()
{
	char num[30];
	int len,i,j,result;
	while(scanf("%s",num)&&atoi(num)){
		len=strlen(num);
		for(i=minbase(num);i<=99;i++){
			result=0;
			for(j=0;j<len;j++){
				result*=i;
				result+=num[j]-'0';
			}
			if(sqrt(result)-floor(sqrt(result))<1e-7){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
