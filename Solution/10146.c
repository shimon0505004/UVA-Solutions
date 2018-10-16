#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
int main(){
	int N,i,depth;
	char spaces[15][15],prev[15],now[15];
	memset(spaces,' ',sizeof(spaces));
	for(i=0;i<15;i++) spaces[i][i]=0;
	scanf("%d ",&N);
	while(N--){
		prev[0]=0;
		depth=0;
		while(fgets(now,15,stdin)!=NULL&&*now!='\n'){
			depth=MIN(depth+1,strlen(now)-1);
			i=0;
			while(prev[i]==now[i]&&++i<depth);
			depth=i;
			printf("%s%s",spaces[depth],now);
			strcpy(prev,now);
		}
		if(N) puts("");
	}
	return 0;
}
