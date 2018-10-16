#include<stdio.h>
int N,M;
int factor[20],M,ans;
int GCD(int a,int b){
	int temp;
	while(a%b) temp=a,a=b,b=temp%b;
	return b;
}
long long LCM(int a,int b){
	return (long long)a/GCD(a,b)*b;
}
void dfs(int depth,int now,int t){
	int i;
	long long lcm;
	for(i=t;i<M;i++){
		lcm=LCM(factor[i],now);
		if(lcm<=(long long)N){
			if(depth&1) ans+=N/lcm;
			else ans-=N/lcm;
			dfs(depth+1,(int)lcm,i+1);
		}
	}
}
int main(){
	int i,j,count=0;
	int m;
	while(scanf("%d%d",&N,&M)==2){
		for(i=0;i<M;i++) scanf("%d",&factor[i]);
		ans=N;
		dfs(0,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
