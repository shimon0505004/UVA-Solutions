#include<stdio.h>
int main(){
	int n,m,i;
	while(scanf("%d",&n)==1){
		if(n<4) puts("Impossible");
		else if(n%6==0||n%6==4){
			m=n/2;
			printf("2");
			for(i=2;i<=m;i++) printf(" %d",2*i);
			for(i=1;i<=m;i++) printf(" %d",2*i-1);
			puts("");
		}else if(n%6==5||n%6==1){
			m=n/2;
			printf("1");
			for(i=2;i<=m+1;i++) printf(" %d",2*i-1);
			for(i=1;i<=m;i++) printf(" %d",2*i);
			puts("");
		}else{
			int start=n/6*3,even=n/2*2,half=even/2;
			printf("%d",start+1);
			for(i=1;i<half;i++) start=(start+2)%even,printf(" %d",start+1);
			start=even-3-start;
			for(i=0;i<half;i++) start=(start+2)%even,printf(" %d",start+1);
			if(n%6==3) printf(" %d",n);
			puts("");
		}
	}
	return 0;
}
