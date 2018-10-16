#include<stdio.h>
#include<string.h>
int answers[80][80][2];
int n_answers[80];
char visit[10];
void push(int N,int n1,int n2){
	answers[N][n_answers[N]][0]=n1;
	answers[N][n_answers[N]][1]=n2;
	n_answers[N]++;
}
void dfs(int depth,int now){
	int i,j,temp;
	char copy[10];
	if(depth==5){
		for(i=2;i<80;i++)
			if(now%i==0){
				temp=now/i;
				memcpy(copy,visit,sizeof(visit));
				for(j=0;j<5;j++){
					if(copy[temp%10]) break;
					copy[temp%10]=1;
					temp/=10;
				}
				if(j==5) push(i,now,now/i);
			}
		return;
	}
	for(i=0;i<10;i++){
		if(visit[i]) continue;
		visit[i]=1;
		dfs(depth+1,now*10+i);
		visit[i]=0;
	}
}
int main(){
	int N,start=0,i;
	memset(n_answers,0,sizeof(n_answers));
	memset(visit,0,sizeof(visit));
	dfs(0,0);
	while(scanf("%d",&N),N){
		if(start) puts("");
		start=1;
		if(n_answers[N]==0) printf("There are no solutions for %d.\n",N);
		else
			for(i=0;i<n_answers[N];i++)
				printf("%.5d / %.5d = %d\n",answers[N][i][0],answers[N][i][1],N);
	}
	return 0;
}
