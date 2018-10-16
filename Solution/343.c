#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define digit 31 
int temp;
int change(char num)
{
	if(isdigit(num)) return num-'0';
	else return num-'A'+10;
}
int real(char *num,int base)
{
	int len=strlen(num),i,t=1;
	int result=0;
	for(i=len-1;i>=0;i--,t*=base){
		temp=change(num[i]);
		if(temp>=base) return -1;
		result+=temp*t;
	}
	return result;
}
int main()
{
	int exit,base1,base2,r1,r2;
	char n1[digit],n2[digit];
	while(scanf("%s%s",n1,n2)==2){
		exit=0;
		for(base1=2;base1<=36&&!exit;base1++){
			r1=real(n1,base1);
			if(r1==-1){
				base1=temp;
				continue;
			}
			for(base2=2;base2<=36&&!exit;base2++){
				r2=real(n2,base2);
				if(r2==-1){
					base2=temp;
					continue;
				}
				if(r1==r2){
					printf("%s (base %d) = %s (base %d)\n",n1,base1,n2,base2);
					exit=1;
				}
				else if(r1<r2)
					break;
			}
		}
		if(!exit)
			printf("%s is not equal to %s in any base 2..36\n",n1,n2);
	}
	return 0;
}
