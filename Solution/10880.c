#include<stdio.h>
#include<math.h>
int main(){
	int cases,i,j,sqr,C,R,factor[10000],count;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		scanf("%d%d",&C,&R);
		printf("Case #%d:",i);
		if(C==R){
			puts(" 0");
			continue;
		}
		C-=R;
		sqr=(int)(sqrt(C)+1);
		count=0;
		for(j=1;j<=sqr;j++)
			if(C%j==0){
				factor[count++]=C/j;
				if(j>R) printf(" %d",j),R=j;
			}
		for(j=count-1;j>=0;j--)
			if(factor[j]>R) printf(" %d",factor[j]);
		puts("");
	}
	return 0;
}
