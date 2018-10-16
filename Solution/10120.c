#include<stdio.h>
#include<string.h>
#define Ubound 48
#define MAX(x,y) (x)>(y)?(x):(y)
int frank[Ubound+1][Ubound+1];
int rocks,dest;
void dfs(int depth,int pos,int max){
	int jump=2*depth-1,i;
	if(pos>Ubound||pos<=0) return;
	if(!frank[pos][max])
		for(i=max;i<=Ubound;i++)
			frank[pos][i]=1;
	dfs(depth+1,pos+jump,MAX(pos+jump,max));
	dfs(depth+1,pos-jump,max);
}
int main()
{
	int i,j;
	memset(frank,0,sizeof(frank));
	dfs(2,1,1);
	while(scanf("%d%d",&rocks,&dest),rocks+dest){
		if(rocks>Ubound) puts("Let me try!");
		else
			if(frank[dest][rocks]) puts("Let me try!");
			else puts("Don't make fun of me!");
	}
	return 0;
}
