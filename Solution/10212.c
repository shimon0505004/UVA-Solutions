#include<stdio.h>
int countfac(int n)
{
	int result,rest,restfac,i;
	if(n==0||n==1) return 1;
	result=6;
	rest=n%10;
	for(i=1,restfac=1;i<=rest;i++)
		restfac*=i;
	n/=10;
	n<<=1;
	if(rest>=5){
		n++;
		restfac/=5;
	}
	restfac%=10;
	result*=countfac(n);
	n%=4;
	result<<=(4-n);
	result*=restfac;
	result%=10;
	return result;
}
int main()
{
	int N,M,count,i,result,t;
	while(scanf("%d%d",&N,&M)==2){
		if(M==0)
			puts("1");
		else if(M<14){
			count=0;
			result=1;
			for(i=N;i>(N-M);i--){
				t=i;
				while(!(t%10))
					t/=10;
				while(!(t%2))
					t/=2,count++;
				while(!(t%5))
					t/=5,count--;
				result=((result*t)%10);
			}
			if(count>0)
				while(count--)
					result<<=1,result%=10;
			else if(count<0)
				while(count++)
					result*=5;
			while(!(result%10))
				result/=10;
			printf("%d\n",result%10);
		}else
			printf("%d\n",(countfac(N)*96/countfac(N-M))%10);
	}
	return 0;
}
