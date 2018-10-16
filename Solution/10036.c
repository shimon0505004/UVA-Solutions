#include<stdio.h>
#include<string.h>
int main(){
	int cases,i,j,N,temp,K;
	char mod[10005][105];
	scanf("%d",&cases);
	while(cases--){
		memset(mod,0,sizeof(mod));
		scanf("%d%d",&N,&K);
		scanf("%d",&temp);
		mod[0][abs(temp)%K]=1;
		for(i=1;i<N;i++){
			scanf("%d",&temp);
			temp=abs(temp)%K+K;
			for(j=0;j<K;j++)
				if(mod[i-1][j])
					mod[i][(temp+j)%K]=mod[i][(temp-j)%K]=1;
		}
		if(mod[N-1][0]) puts("Divisible");
		else puts("Not divisible");
	}
	return 0;
}
