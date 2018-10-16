#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int answers[450],n_answer,dig;
char visit[10],digits[10];
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
void dfs(int depth,int now){
	int i,next;
	if(depth==dig){
		for(answers[n_answer]=0,i=0;i<dig;i++)
			answers[n_answer]*=10,answers[n_answer]+=digits[i];
		n_answer++;
		return;
	}
	for(i=1;i<10;i++){
		next=(now+i)%dig;
		if(visit[i]||next==now) continue;
		if((next==0&&depth==dig-1)||digits[next]==0){
			visit[i]=1;
			digits[now]=i;
			dfs(depth+1,next);
			digits[now]=0;
			visit[i]=0;
		}
	}
}
int main(){
	int i,n,cases;
	n_answer=0;
	for(dig=2;dig<=7;dig++){
		memset(visit,0,sizeof(visit));
		memset(digits,0,sizeof(digits));
		dfs(0,0);
	}
	qsort(answers,n_answer,sizeof(int),compar);
	for(cases=1;scanf("%d",&n),n;cases++){
		for(i=0;n>answers[i];i++);
		printf("Case %d: %d\n",cases,answers[i]);
	}
	return 0;
}
