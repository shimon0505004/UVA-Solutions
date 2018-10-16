#include<stdio.h>
int main()
{
	int check,isleap,start=0,checkleap,checkhuluculu,evendigit,odddigit;
	int i,check11,len;
	char years[10000]={0},*Ptr;
	while(scanf("%s",years)==1){
		if(start) printf("\n");
		start=1;
		isleap=0;
		check=0;
		len=strlen(years);
		Ptr=years;
		if(len>4)
			Ptr+=len-4;

		checkleap=atoi(Ptr);
		if(!(checkleap%4))
			if(checkleap%100){
				printf("This is leap year.\n");
				isleap=check=1;
			}
			else if(!(checkleap%400)){
				printf("This is leap year.\n");
				isleap=check=1;
			}
		Ptr=years;
		checkhuluculu=0;
		for(i=0;i<len;i++)
			checkhuluculu+=years[i]-'0';
		if(!(checkhuluculu%3)&&!((years[len-1]-'0')%5)){
			printf("This is huluculu festival year.\n");
			check=1;
		}
		evendigit=odddigit=0;
		for(i=0;i<len;i++)
			if(i%2)
				evendigit+=years[i]-'0';
			else
				odddigit+=years[i]-'0';
		check11=abs(odddigit-evendigit);
		if(!(check11%11)&&!((years[len-1]-'0')%5)&&isleap){
			printf("This is bulukulu festival year.\n");
			check=1;
		}
		if(!check)
			printf("This is an ordinary year.\n");
		memset(years,0,sizeof(years));
	}
	return 0;
}
