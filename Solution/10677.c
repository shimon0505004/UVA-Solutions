#include<stdio.h>
int main(){
	int b1,b2,U,L;
	int cases,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d%d",&b1,&b2,&L,&U);
		for(i=U-1;i>L;i--){
			int n1=i,n2=0,t;
			for(t=1;n1>0;t*=b2){
				n2+=(n1%b1)*t;
				n1/=b1;
			}
			n1=i;
			if(n2%n1==0){
				printf("%d\n",i);
				break;
			}
		}
		if(i==L) puts("Non-existent.");
	}
	return 0;
}
