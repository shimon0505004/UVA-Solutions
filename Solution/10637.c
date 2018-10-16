#include<stdio.h>
#include<string.h>
char rprime[105][105];
char restN[105];
int out[35];
int need,split;
struct array{
	char a[105];
};
int GCD(int a,int b){
	int temp;
	while(a%b)
		temp=a,a=b,b=temp%b;
	return b;
}
void dfs(int start,int depth,int rest,struct array a){
	int i,j;
	struct array temp;
	if(depth==split-1){
		if(!a.a[rest]){
			for(i=0;i<split-1;i++)
				printf("%d ",out[i]);
			printf("%d\n",rest);
		}
	}else{
		for(i=start;2*i<=rest;i++){
			if(a.a[i]) continue;
			temp=a;
			for(j=start;j<=rest-start;j++)
				if(rprime[i][j]) temp.a[j]=1;
			out[depth]=start=i;
			dfs(start,depth+1,rest-i,temp);
		}
	}

}
int main()
{
	int N;
	int i,j;
	struct array a;
	memset(rprime,0,sizeof(rprime));
	for(i=2;i<101;i++)
		for(j=2;j<101;j++)
			if(GCD(i,j)!=1)
				rprime[i][j]=rprime[j][i]=1;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d%d",&need,&split);
		printf("Case %d:\n",i);
		memset(restN,0,sizeof(restN));
		memset(a.a,0,sizeof(a.a));
		dfs(1,0,need,a);
	}
	return 0;
}
