#include<stdio.h>
int main()
{
	int lights[105];
	int i,min,n,j;
	while(1){
		for(n=0;scanf("%d",&lights[n])==1;n++)
			if(!lights[n]) break;
		if(!lights[0]) break;
		min=100;
		for(i=0;i<n;i++)
			if(lights[i]<min) min=lights[i];
		for(i=2*min;i<=5*3600;i++){
			for(j=0;j<n;j++)
				if((i%(2*lights[j]))>(lights[j]-6)) break;
			if(j==n){
				printf("%.2d:%.2d:%.2d\n",i/3600,(i%3600)/60,i%60);
				break;
			}
			if(i%(2*min)==min-5) i+=min+4;
		}
		if(i>5*3600) puts("Signals fail to synchronise in 5 hours");
	}
	return 0;
}
