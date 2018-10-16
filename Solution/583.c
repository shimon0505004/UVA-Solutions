#include<stdio.h>
#include<math.h>
int main()
{
	int num,i,start;
	while(1){
		scanf("%d",&num);
		if(num==0) break;
		printf("%d = ",num);
		start=0;
		if(num<0){
			printf("-1");
			num*=-1;
			start=1;
		}
		for(i=2;sqrt(num)>=i;i++){
			if(!(i%2) && i>2) continue;
			if(!(i%3) && i>3) continue;
			if(!(i%5) && i>5) continue;
			while(!(num%i)){
				if(start) printf(" x ");
				start=1;
				printf("%d",i);
				num/=i;
			}
		}
		if(num!=1 && start) 
			printf(" x %d",num);
		else if(num!=1)
			printf("%d",num);
		printf("\n");
	}
	return 0;
}
