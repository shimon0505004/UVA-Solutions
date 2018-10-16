#include<stdio.h>
int main(){
	int N,L1,L2;
	long long price[301][301]={0};
	int i,j;
	char input[20];
	price[0][0]=1;
	for(i=1;i<301;i++)
		for(j=0;j<301;j++){
			price[i][j]=price[i-1][j];
			if(j>=i) price[i][j]+=price[i][j-i];
		}
	while(fgets(input,20,stdin)!=NULL){
		switch(sscanf(input,"%d%d%d",&N,&L1,&L2)){
			case 1:
				printf("%lld\n",price[N][N]);
				break;
			case 2:
				if(L1>300) L1=300;
				printf("%lld\n",price[L1][N]);
				break;
			case 3:
				if(N==0){
					if(L1>0){
						puts("0");
						break;
					}else{
						puts("1");
						break;
					}
				}
				if(L1>300) L1=300;
				else if(L1==0) L1=1;
				if(L2>300) L2=300;
				printf("%lld\n",price[L2][N]-price[L1-1][N]);
		}
	}
	return 0;
}
