#include<stdio.h>
#include<math.h>
int main()
{
	int cases,n1,n2,i,j,k,nprime,divisor,num,maxdivisor,maxk;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d%d",&n1,&n2);
		printf("Between %d and %d, ",n1,n2);
		maxdivisor=0;
		for(k=n1,maxk=n1;k<=n2;k++){
			num=k;
			if(k==1)
				divisor=1;
			else{
				divisor=1;
				for(j=2;sqrt(num)>=j||num==3||num==2;j++){
					if(!(j%2) && j>2) continue;
					if(!(j%3) && j>3) continue;
					if(!(j%5) && j>5) continue;
					nprime=0;
					while(!(num%j)){
						nprime++;
						num/=j;
					}
					divisor*=(nprime+1);
				}
			}
			if(num!=1)
				divisor*=2;
			if(divisor>maxdivisor){
				maxdivisor=divisor;
				maxk=k;
			}
		}
		printf("%d has a maximum of %d divisors.\n",maxk,maxdivisor);
	}
	return 0;
}
