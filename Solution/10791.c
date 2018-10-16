#include<stdio.h>
#include<math.h>
int main()
{
	int i,start,cases,temp,num;
	long long total;
	for(cases=1;scanf("%lld",&num)==1&&num;cases++){
		printf("Case %d: ",cases);
		total=0;
		for(i=2;sqrt(num)>=i;i++){
			if(!(i%2) && i>2) continue;
			if(!(i%3) && i>3) continue;
			if(!(i%5) && i>5) continue;
			temp=1;
			while(!(num%i)){
				num/=i;
				temp*=i;
			}
			if(temp-1)
				total+=temp;
		}
		if(!total)
			total=(long long)num+1;
		else if(num-1)
			total+=num;
		if(total==temp)
			total++;
		printf("%lld\n",total);
	}
	return 0;
}
