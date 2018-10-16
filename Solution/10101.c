#include<stdio.h>
#include<string.h>
int main()
{
	int cases=0,i,len,start;
	int n;
	char num[20],*numPtr,digit;
	char calls[4][10]={"kuti","lakh","hajar","shata"};
	while(scanf("%s",num)==1){
		len=strlen(num);
		numPtr=num;
		printf("%4d.",++cases);
		start=0;
		if(len==15){
			sscanf(numPtr,"%1d",&n);
			if(n){
				printf(" %d %s",n,calls[0]);
				numPtr+=1;
				len-=1;
				start=1;
			}
		}
		digit=7;
		for(i=0;i<2;i++){
			if(len>5+digit){
				if(len-digit-5==2)
					sscanf(numPtr,"%2d",&n);
				else
					sscanf(numPtr,"%1d",&n);
				numPtr+=(len-digit-5);
				len-=(len-digit-5);
				if(n){
					printf(" %d %s",n,calls[1]);
					start=1;
				}
			}
			if(len>3+digit){
				if(len-digit-3==2)
					sscanf(numPtr,"%2d",&n);
				else
					sscanf(numPtr,"%1d",&n);
				numPtr+=(len-digit-3);
				len-=(len-digit-3);
				if(n){
					printf(" %d %s",n,calls[2]);
					start=1;
				}
			}
			if(len>2+digit){
				sscanf(numPtr,"%1d",&n);
				numPtr+=1;
				len-=1;
				if(n){
					printf(" %d %s",n,calls[3]);
					start=1;
				}
			}
			if(len>digit){
				if(len-digit==2)
					sscanf(numPtr,"%2d",&n);
				else
					sscanf(numPtr,"%1d",&n);
				numPtr+=(len-digit);
				len-=(len-digit);
				if(n)
					printf(" %d",n);
				else if(!n && !start)
					printf(" 0");
				if(digit) printf(" %s",calls[0]);
			}
			digit=0;
		}
		printf("\n");
	}
	return 0;
}
