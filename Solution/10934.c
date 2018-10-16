#include<stdio.h>
int main(){
	long long B[64][64],n;
	int i,j,k;
	for(i=0;i<64;i++) B[1][i]=i;
	for(i=2;i<64;i++){
		B[i][0]=0;
		for(j=1;j<64;j++)
			B[i][j]=B[i][j-1]+B[i-1][j-1]+1;
	}
	while(scanf("%d%lld",&k,&n),k!=0&&n!=0){
		if(k>63) k=63;
		if(n>B[k][63]) puts("More than 63 trials needed.");
		else{
			for(i=1;i<64&&B[k][i]<n;i++);
			printf("%d\n",i);
		}
	}
	return 0;
}
