#include<stdio.h>

long counttimes(long num)
{
	long n=1;
	while(num!=1){
		if(num%2==1)
			num=3*num+1;
		else
			num/=2;
		n++;
	}
	return n;
}
int main()
{
	long i=0,j,mcl=0,n1,n2,flag,min,max;
	while(scanf("%ld %ld",&n1,&n2)==2){
		mcl=0;
		if(n1>n2){
			min=n2;
			max=n1;
		}
		else{
			min=n1;
			max=n2;
		}
		for(j=min;j<=max;j++){
			if(j%2==0){
				if(j%3==0 || j%3==2)
					mcl=(mcl<counttimes(j)?counttimes(j):mcl);
				else
					if((j-1)%3<min)
						mcl=(mcl<counttimes(j)?counttimes(j):mcl);
			}
			else
				if(2*j>max)
					mcl=(mcl<counttimes(j)?counttimes(j):mcl);
		}
		printf("%ld %ld %ld\n",n1,n2,mcl);
	}
	return 0;
}
