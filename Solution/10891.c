#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,game[105],i,j,l;
	int optimal[105][105],subsum[105];
	while(scanf("%d",&n),n){
		subsum[0]=0;
		for(i=1;i<=n;i++) scanf("%d",&game[i]),subsum[i]=subsum[i-1]+game[i];
		memset(optimal,0,sizeof(optimal));
		for(i=1;i<=n;i++) optimal[i][i]=game[i];
		for(l=2;l<=n;l++){
			for(i=1;i<=n-l+1;i++){
				int head=i,tail=i+l-1;
				int max=-2147483647,t;
				for(j=head;j<tail;j++){
					int t;
					t=(subsum[tail]-subsum[j])-optimal[head][j];
					if(t>max) max=t;
					t=(subsum[j]-subsum[head-1])-optimal[j+1][tail];
					if(t>max) max=t;
				}
				if((t=subsum[tail]-subsum[head-1])>max) max=t;
				optimal[head][tail]=max;
			}
		}
		printf("%d\n",optimal[1][n]);
	}
	return 0;
}
