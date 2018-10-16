#include<stdio.h>
#include<string.h>
#define MODULI 1000000000
#define SIZE 200
struct BigNum{
	int n[SIZE];
};
void add(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<SIZE;i++)
		dest->n[i]+=src->n[i];
	for(i=0;i<SIZE-1;i++){
		dest->n[i+1]+=dest->n[i]/MODULI;
		dest->n[i]%=MODULI;
	}
}
void assign(struct BigNum *dest,struct BigNum *src){
	memcpy(dest,src,sizeof(struct BigNum));
}
void printBigNum(struct BigNum *bn){
	int i;
	for(i=SIZE-1;i>0&&bn->n[i]==0;i--);
	printf("%d",bn->n[i--]);
	for(;i>=0;i--) printf("%.9d",bn->n[i]);
	puts("");
}
int main(){
	int i,j,N,prev,now;
	struct BigNum bloque[2][905];
	struct BigNum ans[905];
	memset(bloque,0,sizeof(bloque));
	memset(ans,0,sizeof(ans));
	ans[1].n[0]=1;
	bloque[0][0].n[0]=bloque[1][1].n[0]=1;
	prev=1;
	for(i=2;i<905;i++){
		now=i&1;
		for(j=1;j<=i;j++){
			assign(&bloque[now][j],&bloque[now][j-1]);
			add(&bloque[now][j],&bloque[prev][j-1]);
		}
		assign(&ans[i],&bloque[now][i]);
		memset(&bloque[now][0],0,sizeof(struct BigNum));
		assign(&bloque[prev][0],&bloque[now][i]);
		prev=now;
	}
	while(scanf("%d",&N),N){
		printf("%d, ",N);
		printBigNum(&ans[N]);
	}
	return 0;
}
