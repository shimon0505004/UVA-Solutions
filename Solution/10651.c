#include<stdio.h>
#include<string.h>
#define sh(a) (1<<(a))
char visit[1<<12];
int min;
void dfs(int now){
	int next,count=0;
	int i;
	for(i=0;i<12;i++) if(sh(i)&now) count++;
	if(min>count) min=count;
	for(i=0;i<10;i++)
		if((sh(i)&now)&&(sh(i+1)&now)&&(sh(i+2)&(~now))){
			next=now;
			next|=sh(i+2),next&=~sh(i+1),next&=~sh(i);
			if(visit[next]==0){
				visit[next]=1;
				dfs(next);
			}
		}
	for(i=2;i<12;i++)
		if((sh(i)&now)&&(sh(i-1)&now)&&(sh(i-2)&(~now))){
			next=now;
			next|=sh(i-2),next&=~sh(i-1),next&=~sh(i);
			if(visit[next]==0){
				visit[next]=1;
				dfs(next);
			}
		}
}
int main(){
	int cases;
	char pebble[15];
	int i;
	scanf("%d ",&cases);
	while(cases--){
		int code=0;
		fgets(pebble,15,stdin);
		for(i=0;i<12;i++)
			code=(code<<1)+(pebble[i]=='o'?1:0);
		memset(visit,0,sizeof(visit));
		min=12;
		dfs(code);
		printf("%d\n",min);
	}
	return 0;
}
