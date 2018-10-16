#include<stdio.h>
int main()
{
	int cases,n,m,FIB1,FIB2,FIB_temp;
	int i;
	int mod[4]={60,300,1500,15000};
	int t[4]={10,100,1000,10000};
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d%d",&FIB1,&FIB2,&n,&m);
		n%=mod[m-1];
		if(n){
			for(i=1;i<n;i++){
				FIB_temp=(FIB1+FIB2)%t[m-1];
				FIB1=FIB2;
				FIB2=FIB_temp;
			}
			printf("%d\n",FIB2%t[m-1]);
		}
		else
			printf("%d\n",FIB1%t[m-1]);
	}
	return 0;
}
