#include<stdio.h>
int deficit(int s,int d){
	int i;
	for(i=1;i<=4;i++){
		if(d*i>s*(5-i)){
			int sum=s*(12-i*2)-d*2*i;
			if(i==4) sum-=s+d;
			if(sum>0) return i;
		}
	}
	return -1;
}
int main(){
	int s,d;
	while(scanf("%d%d",&s,&d)==2){
		int n;
		if((n=deficit(s,d))==-1) puts("Deficit");
		else if(n==4) printf("%d\n",s*3-d*9);
		else printf("%d\n",s*(12-n*2)-d*2*n);
	}
	return 0;
}
