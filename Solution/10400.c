#include<stdio.h>
#include<string.h>
int a[105],flag;
char used[105][64008];
char o[105];
int need,n;
void dfs(int depth,int now){
	int i;
	if(flag) return;
	if(now>32000||now<-32000) return;
	if(used[depth][now+32000]) return;
	used[depth][now+32000]=1;
	if(depth==n){
		if(now==need){
			flag=1;
			printf("%d",a[0]);
			for(i=1;i<n;i++)
				printf("%c%d",o[i],a[i]);
			printf("=%d\n",need);
		}
		return;
	}
	o[depth]='+';
	dfs(depth+1,now+a[depth]);
	o[depth]='-';
	dfs(depth+1,now-a[depth]);
	o[depth]='*';
	dfs(depth+1,now*a[depth]);
	if(now%a[depth]==0){
		o[depth]='/';
		dfs(depth+1,now/a[depth]);
	}
	return;
}
int main()
{
	int cases,i;
	scanf("%d",&cases);
	while(cases--){
		memset(used,0,sizeof(used));
		flag=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&need);
		dfs(1,a[0]);
		if(!flag)
			puts("NO EXPRESSION");
	}
	return 0;
}
