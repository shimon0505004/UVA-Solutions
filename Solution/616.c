#include<stdio.h>
#include<math.h>
char divide(int n_coco,int n_man){
	int i;
	for(i=0;i<n_man;i++){
		n_coco--;
		if(n_coco%n_man!=0) return 0;
		n_coco=n_coco/n_man*(n_man-1);
	}
	if(n_coco%n_man==0) return 1;
	return 0;
}
int main(){
	int n_coco,divisor;
	while(scanf("%d",&n_coco),n_coco>=0){
		if(n_coco==0) puts("0 coconuts, no solution");
		for(divisor=(int)sqrt(n_coco)+1;divisor>1;divisor--){
			if((n_coco-1)%divisor==0&&divide(n_coco,divisor)){
				printf("%d coconuts, %d people and 1 monkey\n",n_coco,divisor);
				break;
			}
		}
		if(divisor==1) printf("%d coconuts, no solution\n",n_coco);
	}
	return 0;
}
