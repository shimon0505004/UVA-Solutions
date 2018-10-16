#include<stdio.h>
int main(){
	int n,i,output,start;
	while(scanf("%d",&n),n){
		start=0;
		for(i=0;i<n;i++){
			scanf("%d",&output);
			if(output!=0){
				if(start) putchar(' ');
				printf("%d",output);
				start=1;
			}
		}
		if(start==0) puts("0");
		else puts("");
	}
	return 0;
}
