#include<stdio.h>
int main(){
	int vec[10];
	int cases,n,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		if(n==0) puts("0");
		else if(n==1) puts("1");
		else{
			for(i=9;i>=2;i--){
				vec[i]=0;
				while(n%i==0) vec[i]++,n/=i;
			}
			if(n!=1) puts("-1");
			else{
				for(i=2;i<=9;i++)
					while(vec[i]--)
						putchar(i+'0');
				puts("");
			}
		}
	}
	return 0;
}
