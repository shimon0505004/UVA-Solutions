#include<stdio.h>
#include<string.h>
int main(){
	int Hash[27][352][27];
	int i,j,k,m;
	int L,S,cases;
	memset(Hash,0,sizeof(Hash));
	for(i=0;i<27;i++){
		for(j=0;j<352;j++){
			for(k=0;k<27;k++){
				if(i==1&&j==k) Hash[i][j][k]=1;
			}
		}
	}
	for(i=2;i<27;i++){
		for(j=1;j<353;j++){
			for(k=1;k<27;k++){
				for(m=k+1;m<27;m++){
					if(j-k<0) continue;
					Hash[i][j][k]+=Hash[i-1][j-k][m];
				}
			}
		}
	}
	for(cases=1;scanf("%d%d",&L,&S),L+S;cases++){
		int tot=0;
		printf("Case %d: ",cases);
		if(L>26||S>351){
			puts("0");
			continue;
		}
		for(i=0;i<27;i++) tot+=Hash[L][S][i];
		printf("%d\n",tot);
	}
	return 0;
}
