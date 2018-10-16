#include<stdio.h>
#include<string.h>
int maxlen,base;
char ans[55],candidate[30];
char now[55];
void dfs(int n,int depth){
	int i,rem=0,ndepth=depth+1,max;
	now[depth-1]=n;
	if(maxlen<depth) memcpy(ans,now,sizeof(char[depth])),maxlen=depth;
	for(i=0;i<depth;i++) rem=((rem+now[i])*base)%ndepth;
	max=(base+rem)%ndepth;
	for(i=base-max;i>=0;i-=ndepth)
		if(candidate[i]) dfs(i,ndepth);
}
int main(){
	int i;
	char tmp[15];
	while(scanf("%d%s",&base,tmp)==2){
		memset(candidate,0,sizeof(candidate));
		for(i=0;tmp[i];i++) candidate[(int)tmp[i]-'0']=1;
		maxlen=-1;
		for(i=base-1;i>0;i--) if(candidate[i]) dfs(i,1);
		for(i=0;i<maxlen;i++) putchar(ans[i]+'0');
		puts("");
	}
	return 0;
}
