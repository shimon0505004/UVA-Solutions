#include<stdio.h>
int main()
{
	int n,Nim,i,j;
	int binary[31],check;
	unsigned test;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		memset(binary,0,sizeof(binary));
		for(i=0;i<n;i++){
			scanf("%d",&Nim);
			test=1<<31;
			for(j=0;j<31;j++){
				test>>=1;
				if(test&Nim)
					binary[30-j]++;
			}
		}
		check=0;
		for(i=0;i<30;i++)
			if(binary[i]%2){
				check=1;
				break;
			}
		if(check)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
