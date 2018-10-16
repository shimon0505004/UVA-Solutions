#include<stdio.h>
#define B 0
#define S 1
#define MAX(a,b) ((a)>(b)?(a):(b))
char getStone(int *st){
	char str[20];
	scanf("%s",str);
	sscanf(str+2,"%d",st);
	if(str[0]=='B') return B;
	else return S;
}
int caldis(int s_stone[],int n,int lB,int rB){
	int i,ret=0;
	if(n<=1) return rB-lB;
	ret=MAX(s_stone[0]-lB,ret);
	for(i=2;i<n;i+=2) ret=MAX(s_stone[i]-s_stone[i-2],ret);
	ret=MAX(rB-s_stone[i-2],ret);
	ret=MAX(s_stone[1]-lB,ret);
	for(i=3;i<n;i+=2) ret=MAX(s_stone[i]-s_stone[i-2],ret);
	ret=MAX(rB-s_stone[i-2],ret);
	return ret;
}
int main(){
	int T,cases;
	int N,D,i;
	int lB,rB,cnt,minimax;
	int maxdis;
	int s_stone[105],st;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d",&N,&D);
		lB=0,cnt=0;
		minimax=0;
		for(i=0;i<N;i++){
			char size=getStone(&st);
			if(size==B){
				rB=st;
				maxdis=caldis(s_stone,cnt,lB,rB);
				minimax=MAX(minimax,maxdis);
				cnt=0,lB=st;
			}else s_stone[cnt++]=st;
		}
		rB=D;
		maxdis=caldis(s_stone,cnt,lB,rB);
		minimax=MAX(minimax,maxdis);
		printf("Case %d: %d\n",cases,minimax);
	}
	return 0;
}
