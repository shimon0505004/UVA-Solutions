#include<stdio.h>
#include<string.h>
int main()
{
	int guessnum,num[10],i;
	char compare[15]={0},temp[10];
	while(1){
		for(i=0;i<10;i++)
			num[i]=1;
		while(1){
			memset(compare,0,sizeof(compare));
			scanf("%d",&guessnum);
			if(guessnum==0) return 0;
			scanf("%s%s",temp,compare);
			if(strcmp(compare,"high")==0)
				for(i=guessnum-1;i<10;i++)
					num[i]=0;
			else if(strcmp(compare,"low")==0)
				for(i=guessnum-1;i>=0;i--)
					num[i]=0;
			else
				if(num[guessnum-1]==1){
					printf("Stan may be honest\n");
					break;
				}
				else{
					printf("Stan is dishonest\n");
					break;
				}
		}
	}
	return 0;
}
