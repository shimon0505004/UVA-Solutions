#include<stdio.h>
int main()
{
	int m,n,num,count,i,primetimes;
	int factor[10],times[10];
	while(scanf("%d%d",&m,&n)==2){
		if(!n){
			printf("%d does not divide %d!\n",n,m);
			continue;
		}
		if(m==0||m==1){
			if(n==1)
				printf("%d divides %d!\n",n,m);
			else
				printf("%d does not divide %d!\n",n,m);
			continue;
		}
		if(m>=n){
			printf("%d divides %d!\n",n,m);
			continue;
		}
		memset(times,0,sizeof(times));
		memset(factor,0,sizeof(factor));
		num=n;
		for(i=2,count=0;num>=i*i||num==2||num==3;i++)
			if(!(num%i)){
				factor[count]=i;
				while(!(num%i)){
					num/=i;
					times[count]++;
				}
				count++;
			}
		if(num!=1){
			factor[count]=num;
			times[count]=1;
		}
		for(count=0;factor[count];count++){
			primetimes=0;
			num=m;
			while(num)
				primetimes+=(num/=factor[count]);
			if(primetimes<times[count]){
				printf("%d does not divide %d!\n",n,m);
				break;
			}
		}
		if(!factor[count])
			printf("%d divides %d!\n",n,m);
	}
	return 0;
}
