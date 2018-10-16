#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n=1,hostage[3520],pos,p;
	long prime[3520],sq;
	prime[0]=2;
	prime[1]=3;
	for(i=2;n<3519;i++){
		sq=(long)sqrt(i);
		for(j=2;j<=sq;j++)
			if(i%j==0) break;
			else if(j==sq){
				n++;
				prime[n]=i;
			}
	}
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
			hostage[i]=i+1;
		pos=0;
		for(i=0;i<n-1;i++){
			p=prime[i]%(n-i);
			pos=(pos+p+n-i-1)%(n-i);
			for(j=pos;j<n-i;j++)
				hostage[j]=hostage[j+1];
		}
		for(i=0;i<n;i++)
			if(hostage[i]>0){
				printf("%d\n",hostage[i]);
				break;
			}
	}
	return 0;
}
