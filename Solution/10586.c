#include<stdio.h>
#include<string.h>
int main(){
	int n,k,i,d;
	int coeff[10005];
	while(scanf("%d%d",&n,&k),!(n==-1&&k==-1)){
		memset(coeff,0,sizeof(coeff));
		for(i=0;i<=n;i++)
			scanf("%d",&coeff[i]);
		if(k==0){
			puts("0");
			continue;
		}
		for(i=n;i>=k;i--){
			if((i/k)%2==0)
				coeff[i%k]+=coeff[i];
			else coeff[i%k]-=coeff[i];
		}
		for(d=k-1;d>=0;d--)
			if(coeff[d]!=0) break;
		if(d<k){
			printf("%d",coeff[0]);
			for(i=1;i<=d;i++)
				printf(" %d",coeff[i]);
			puts("");
		}else puts("0");
	}
	return 0;
}
