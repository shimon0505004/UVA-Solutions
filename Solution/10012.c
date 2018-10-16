#include<stdio.h>
#include<math.h>
#include<string.h>
int n,ans[10];
double radii[10],min,w[10];
double table[10][10];
char visit[10];
void dfs(int depth,double now){
	int i,j;
	double t;
	if(now>min) return;
	if(depth==n){
		min=now;
		return;
	}
	for(i=0;i<n;i++){
		if(visit[i]) continue;
		visit[i]=1;
		ans[depth]=i;
		w[depth]=radii[i];
		for(j=0;j<depth;j++)
			if(w[depth]<(t=w[j]+table[i][ans[j]]))
				w[depth]=t;
		t=now;
		if(w[depth]+radii[ans[depth]]>t) t=w[depth]+radii[ans[depth]];
		dfs(depth+1,t);
		visit[i]=0;
	}
}
int main(){
	int N,i,j;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&n);
		min=0;
		for(i=0;i<n;i++) scanf("%lf",&radii[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				table[i][j]=table[j][i]=2.0*sqrt(radii[i]*radii[j]);
		min=1e8;
		memset(visit,0,sizeof(visit));
		dfs(0,0.0);
		printf("%.3lf\n",min);
	}
	return 0;
}
