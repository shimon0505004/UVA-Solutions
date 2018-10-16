#include<stdio.h>
int C(int n,int m){
	int i,result=1;
	if(2*m>n) m=n-m;
	for(i=1;i<=m;i++){
		result*=n-i+1;
		result/=i;
	}
	return result;
}
int main(){
	int table[10][10];
	int i,j,n,result,k;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++) scanf("%d",&table[0][i]);
		scanf("%d",&k);
		for(i=1;i<n;i++)
			for(j=0;j<n-i;j++)
				table[i][j]=table[i-1][j+1]-table[i-1][j];
		result=0;
		k+=n;
		for(i=0;i<n;i++) result+=table[i][0]*C(k-1,i);
		printf("Term %d of the sequence is %d\n",k,result);
	}
	return 0;
}
