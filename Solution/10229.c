#include<stdio.h>
int main()
{
	int cases,n,m,FIB0,FIB1,FIB_temp;
	int i,t;
	while(scanf("%d%d",&n,&m)==2){
		n%=(1<<(m-1))*3;
		if(n&&m){
			FIB0=0,FIB1=1;
			t=1<<m;
			for(i=1;i<n;i++){
				FIB_temp=(FIB0+FIB1)%t;
				FIB0=FIB1;
				FIB1=FIB_temp;
			}
			printf("%d\n",FIB1%t);
		}
		else
			puts("0");
	}
	return 0;
}
