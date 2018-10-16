#include<stdio.h>
#include<string.h>
int main()
{
	int den,num,count,quotient,i;
	char result[1001];
	int remainder[1001];
	while(scanf("%d%d",&num,&den)==2&&(num+den)){
		memset(result,0,sizeof(result));
		memset(remainder,0,sizeof(remainder));
		*result='.';
		count=1;
		remainder[num]=count;
		num*=10;
		while(num){
			quotient=num/den;
			result[count++]=quotient+'0';
			num-=(den*quotient);
			if(remainder[num]) break;
			remainder[num]=count;
			num*=10;
		}
		for(i=0;result[i];i+=50)
			printf("%.50s\n",result+i);
		if(!num)
			puts("This expansion terminates.");
		else
			printf("The last %d digits repeat forever.\n",count-remainder[num]);
		puts("");
	}
	return 0;
}
