#include<stdio.h>
#include<string.h>
int main(){
	int m,n,i,j;
	int Bachet[1000005];
	int stones[15];
	while(scanf("%d%d",&n,&m)==2){
		memset(Bachet,0,sizeof(Bachet));
		for(i=0;i<m;i++)
			scanf("%d",&stones[i]);
		for(i=0;i<=n;i++){
			if(Bachet[i]) continue;
			for(j=0;j<m;j++)
				if(i+stones[j]<=n)
					Bachet[i+stones[j]]=1;
		}
		if(Bachet[n]) puts("Stan wins");
		else puts("Ollie wins");
	}
	return 0;
}
