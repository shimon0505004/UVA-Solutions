#include<stdio.h>
#include<string.h>
#define FILL_A 0
#define FILL_B 1
#define EMPTY_A 2
#define EMPTY_B 3
#define POUR_A_B 4
#define POUR_B_A 5
char *instr[6]={"fill A","fill B","empty A","empty B","pour A B","pour B A"};
char jug[1005][1005];
char steps[1000005];
int Ca,Cb,N;
char dfs(int A,int B,int depth){
	int i,nextA,nextB;
	jug[A][B]=1;
	if(A==N||B==N){
		for(i=0;i<depth;i++) puts(instr[steps[i]]);
		puts("success");
		return 1;
	}
	nextA=Ca,nextB=B;
	if(jug[nextA][nextB]==0){
		steps[depth]=FILL_A;
		if(dfs(nextA,nextB,depth+1)) return 1;
	}
	nextA=A,nextB=Cb;
	if(jug[nextA][nextB]==0){
		steps[depth]=FILL_B;
		if(dfs(nextA,nextB,depth+1)) return 1;
	}
	nextA=0,nextB=B;
	if(jug[nextA][nextB]==0){
		steps[depth]=EMPTY_A;
		if(dfs(nextA,nextB,depth+1)) return 1;
	}
	nextA=A,nextB=0;
	if(jug[nextA][nextB]==0){
		steps[depth]=EMPTY_B;
		if(dfs(nextA,nextB,depth+1)) return 1;
	}
	if(A+B>Cb) nextA=B+A-Cb,nextB=Cb;
	else nextA=0,nextB=A+B;
	if(jug[nextA][nextB]==0){
		steps[depth]=POUR_A_B;
		if(dfs(nextA,nextB,depth+1)) return 1;
	}
	if(A+B>Ca) nextA=Ca,nextB=A+B-Ca;
	else nextA=A+B,nextB=0;
	if(jug[nextA][nextB]==0){
		steps[depth]=POUR_B_A;
		if(dfs(nextA,nextB,depth+1)) return 1;
	}
	return 0;
}
int main(){
	while(scanf("%d%d%d",&Ca,&Cb,&N)==3){
		memset(jug,0,sizeof(jug));
		dfs(0,0,0);
	}
	return 0;
}
