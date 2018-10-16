#include<stdio.h>
int main(){
	int cases;
	int n,k,res,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&k);
		res=0;
		for(i=0;i<n;i++){
			if(k%4==1||k%4==2) res|=1<<i;
			k>>=1;
		}
		printf("%d\n",res);
	}
	return 0;
}
