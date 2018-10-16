#include<stdio.h>
int main()
{
	int i,n,count,temp;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		count=0;
		temp=n;
		for(i=2;i<=temp && temp>1;i++)
			if(temp%i==0){
				count++;
				for(;temp%i==0;)
					temp/=i;
			}
		printf("%d : %d\n",n,count);
	}
	return 0;
}
