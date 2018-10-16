#include<stdio.h>
int main()
{
	int cases,i,dorh,test,j;
	int b1,b2;
	char num[5];
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		memset(num,0,sizeof(num));
		scanf("%s",num);
		sscanf(num,"%d",&dorh);
		test=1<<15;
		b1=0;
		for(j=0;j<15;j++){
			test>>=1;
			if(test&dorh) b1++;
		}
		sscanf(num,"%X",&dorh);
		test=1<<16;
		b2=0;
		for(j=0;j<16;j++){
			test>>=1;
			if(test&dorh) b2++;
		}
		printf("%d %d\n",b1,b2);
	}
	return 0;
}
