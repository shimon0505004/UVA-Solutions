#include<stdio.h>
#include<string.h>
const char *num="0123456789";
long long find(char *input,const char flag)
{
	char *Ptr;
	long long current=(flag=='+'?0:1),result=(flag=='+'?1:0),temp;
	for(Ptr=input;*Ptr;Ptr++)
		if(*Ptr==flag){
			sscanf(Ptr+1,"%lld",&temp);
			if(flag=='+')
				current+=temp;
			else
				current*=temp;
			Ptr+=strspn(Ptr+1,num);
		}
		else{
			sscanf(Ptr+1,"%lld",&temp);
			if(flag=='+')
				result*=current;
			else
				result+=current;
			current=temp;
			Ptr+=strspn(Ptr+1,num);
		}
	return result;
}
int main()
{
	int cases,i;
	long long max,min;
	char input[50],*Ptr;
	scanf("%d ",&cases);
	while(cases--){
		memset(input,0,sizeof(input));
		fgets(input+1,50,stdin);
		*input='*';
		min=find(input,'*');
		*input='+';
		max=find(input,'+');
		printf("The maximum and minimum are %lld and %lld.\n",max,min);
	}
	return 0;
}
