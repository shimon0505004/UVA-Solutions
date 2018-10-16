#include<stdio.h>
#include<string.h>
#define MAXN 100
int main(){
	char a[MAXN],b[MAXN];
	int temp,i;
	char c,equal,dis,bina,ainb;
	while(!feof(stdin)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(;;){
			if(scanf("%d%c ",&temp,&c)!=2) break;
			a[temp]=1;
			if(c!=' ') break;
		}
		for(;;){
			if(scanf("%d%c ",&temp,&c)!=2) break;
			b[temp]=1;
			if(c!=' ') break;
		}
		equal=ainb=bina=dis=1;
		for(i=0;i<MAXN;i++){
			if(a[i]==1)
				if(b[i]==1) dis=0;
				else ainb=equal=0;
			else if(b[i]==1) bina=equal=0;
		}
		if(equal) puts("A equals B");
		else if(ainb) puts("A is a proper subset of B");
		else if(bina) puts("B is a proper subset of A");
		else if(dis) puts("A and B are disjoint");
		else puts("I'm confused!");
	}
	return 0;
}
