#include<stdio.h>
int main()
{
	double a,b;
	char o,input[1000];
	while(fgets(input,1000,stdin)!=NULL){
		sscanf(input,"%lf%*c%c%*c%lf",&a,&o,&b);
		printf("%s",input);
		if(a>2147483647) puts("first number too big");
		if(b>2147483647) puts("second number too big");
		if(o=='+'){
			if(a+b>2147483647) puts("result too big");
		}else
			if(a*b>2147483647) puts("result too big");
	}
	return 0;
}
