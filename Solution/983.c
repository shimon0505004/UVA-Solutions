#include<stdio.h>
#include<string.h>
int main(){
	int N,M,i,j,size;
	int matrix[1005][1005];
	unsigned long long sum;
	char start=0;
	while(scanf("%d%d",&N,&M)==2){
		if(start) puts("");
		else start=1;
		memset(matrix,0,sizeof(matrix));
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				scanf("%d",&matrix[i][j]);
				matrix[i][j]+=matrix[i][j-1];
			}
		}
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				matrix[i][j]+=matrix[i-1][j];
		size=N-M+1;
		sum=0;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++){
				int element=matrix[i+M][j+M]-matrix[i+M][j]-matrix[i][j+M]+matrix[i][j];
				printf("%d\n",element);
				sum+=element;
			}
		printf("%llu\n",sum);
	}
	return 0;
}
