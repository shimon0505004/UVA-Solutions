#include<stdio.h>
#include<string.h>
int main()
{
	int denominator,numerator,den,num;
	int count,quotient,i;
	int repeatingcycle;
	char result[3000],q[10];
	int remainder[3000];
	char cut[4];
	while(scanf("%d%d",&numerator,&denominator)==2){
		memset(q,0,sizeof(q));
		memset(result,0,sizeof(result));
		memset(cut,0,sizeof(cut));
		for(i=0;i<3000;i++)
			remainder[i]=-1;
		den=denominator,num=numerator;
		quotient=num/den;
		q[sprintf(q,"%d",quotient)]='.';
		num-=(den*quotient);
		count=0;
		remainder[num]=count;
		num*=10;
		while(num){
			quotient=num/den;
			result[count++]=quotient+'0';
			num-=(den*quotient);
			if(remainder[num]+1) break;
			remainder[num]=count;
			num*=10;
		}
		if(result[50]){
			strcpy(cut,"...");
			result[50]=0;
		}
		printf("%d/%d = ",numerator,denominator);
		if(!num){
			repeatingcycle=1;
			printf("%s%s(0)\n",q,result);
		}
		else{
			repeatingcycle=count-remainder[num];
			printf("%s%.*s(%s%s)\n",q,remainder[num],result,result+remainder[num],cut);
		}
		printf("   %d = number of digits in repeating cycle\n",repeatingcycle);
		puts("");
	}
	return 0;
}
