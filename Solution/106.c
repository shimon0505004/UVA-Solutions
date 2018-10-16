#include<stdio.h>
int GCD(int i,int j){
	int temp;
	while(i%j)
		temp=j,j=i%j,i=temp;
	return j;
}
int main()
{
	int N,i,j,k,count,count2,u,v,p;
	char num[1000001];
	while(scanf("%d",&N)==1){
		memset(num,0,sizeof(num));
		count=0;
		for(i=1;i*i<N;i++)
			for(j=(i%2)+1;i*i+j*j<=N&&i>j;j+=2)
				if(GCD(i,j)==1){
					u=2*i*j,v=i*i-j*j,p=i*i+j*j;
					for(k=1;p*k<=N;k++)
						num[u*k]=num[v*k]=num[p*k]=1;
					count++;
				}
		for(i=1,count2=0;i<=N;i++)
			if(!num[i]) count2++;
		printf("%d %d\n",count,count2);
	}
	return 0;
}
