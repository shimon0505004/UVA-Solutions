#include<stdio.h>
unsigned long maxn;
unsigned long counttimes(unsigned long num)
{
	unsigned long n=0,temp=num;
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
	unsigned long mcl,n1,n2,min,max,compare,i;
	while(1){
		scanf("%lu %lu",&n1,&n2);
		if(n1+n2==0) break;
		mcl=0;
		if(n1>n2){
			min=n2;
			max=n1;
		}
		else{
			min=n1;
			max=n2;
		}
		if(n1+n2==0)
			break;
		else if(n1+n2==2){
			printf("Between 1 and 1, 1 generates the longest sequence of 3 values.\n");
			continue;
		}
		else if(n1+n2==3){
			printf("Between 1 and 2, 1 generates the longest sequence of 3 values.\n");
			continue;
		}
		for(i=min,mcl=0;i<=max;i++){
			compare=counttimes(i);
			if(compare>mcl){
				mcl=compare;
				maxn=i;
			}
		}
		printf("Between %lu and %lu, %lu generates the longest sequence of %lu values.\n",min,max,maxn,mcl);
	}
	return 0;
}
