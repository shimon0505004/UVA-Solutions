#include<stdio.h>
#include<string.h>
int main()
{
	char num[105],*Ptr;
	int check,result,onetotwenty[21]={0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4,4};
	while(1){
		scanf("%s",num);
		if(*num=='0') break;
		result=0;
		Ptr=num;
		if(strlen(num)>2)
			Ptr+=strlen(num)-2;
		sscanf(Ptr,"%d",&check);
		result+=(check/20)*4;
		check%=20;
		result+=onetotwenty[check];
		result%=10;
		printf("%d\n",result);
	}
	return 0;
}
