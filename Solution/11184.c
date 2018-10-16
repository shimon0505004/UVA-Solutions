#include<stdio.h>
int main(){
	int n;
	int cases,i;
	for(cases=1;scanf("%d",&n),n;cases++){
		printf("Case %d:",cases);
		if(n%4==0||n%4==3){
			int now=1;
			printf(" %d",now);
			for(i=1;i<(n+1)/2;i++){
				if(i%2==1) now+=n-i;
				else now-=n-i;
				printf(" %d",now);
			}
			for(i=1;n/2-i>=1;i++){
				if(i%2==1) now-=n/2-i;
				else now+=n/2-i;
				printf(" %d",now);
			}
			now+=n/2;
			printf(" %d\n",now);
		}else puts(" -1");
	}
	return 0;
}
