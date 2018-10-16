#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 300
void build_prime(int prime[]){
	int i,j,count=0;
	char notprime[SIZE]={0};
	for(i=2;i<SIZE/2;i++){
		if(notprime[i]) continue;
		prime[count++]=i;
		for(j=2;i*j<SIZE;j++)
			notprime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++)
		if(!notprime[i]) prime[count++]=i;
}
int prime[62];
int ans[300];
int n,t;
char dfs(int depth,int now,int next){
	if(now>n||depth>t) return 0;
	if(depth==t){
		if(now==n) return 1;
		return 0;
	}
	if(next>=62) return 0;
	if(prime[next]==2){
		if((n+t)%2==0) return dfs(depth,now,next+1);
		ans[depth]=prime[next];
		return dfs(depth+1,now+prime[next],next+1);
	}
	ans[depth]=ans[depth+1]=prime[next];
	if(dfs(depth+2,now+prime[next]*2,next+1)) return 1;
	ans[depth]=prime[next];
	if(dfs(depth+1,now+prime[next],next+1)) return 1;
	if(dfs(depth,now,next+1)) return 1;
	return 0;
}
int compar(const void *a,const void *b){
	int n1=*((int *)a),n2=*((int *)b);
	char str1[5],str2[5];
	sprintf(str1,"%d",n1);
	sprintf(str2,"%d",n2);
	return strcmp(str1,str2);
}
int main(){
	int cases;
	build_prime(prime);
	qsort(prime,62,sizeof(int),compar);
	for(cases=1;scanf("%d%d",&n,&t),n|t;cases++){
		printf("CASE %d:\n",cases);
		if(dfs(0,0,0)){
			int i;
			printf("%d",ans[0]);
			for(i=1;i<t;i++)
				printf("+%d",ans[i]);
			puts("");
		}else puts("No Solution.");
	}
	return 0;
}
