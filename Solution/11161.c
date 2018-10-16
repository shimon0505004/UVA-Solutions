#include<stdio.h>
#include<string.h>
#define SIZE 36
#define MODULI 1000000000
struct BigInt{
	int d[SIZE];
};
void add(struct BigInt *dest,struct BigInt *src){
	int i;
	for(i=0;i<SIZE;i++) dest->d[i]+=src->d[i];
	for(i=0;i<SIZE-1;i++) dest->d[i+1]+=dest->d[i]/MODULI,dest->d[i]%=MODULI;
}
void half(struct BigInt *bi){
	int i;
	for(i=SIZE-1;i>0;i--){
		if(bi->d[i]&1) bi->d[i-1]+=MODULI;
		bi->d[i]>>=1;
	}
	if(bi->d[0]&1) bi->d[0]++;
	bi->d[0]>>=1;
}
void printBigInt(struct BigInt *bi){
	int i;
	for(i=SIZE-1;i>0&&bi->d[i]==0;i--);
	printf("%d",bi->d[i]);
	for(i--;i>=0;i--) printf("%.9d",bi->d[i]);
	puts("");
}
int main(){
	struct BigInt fib[1503];
	int i,n;
	int cases;
	memset(fib,0,sizeof(struct BigInt[2]));
	fib[0].d[0]=1;
	fib[1].d[0]=2;
	for(i=2;i<1503;i++){
		fib[i]=fib[i-1];
		add(&fib[i],&fib[i-2]);
	}
	for(i=0;i<1503;i++) fib[i].d[0]-=2;
	for(cases=1;scanf("%d",&n),n;cases++){
		struct BigInt ans;
		ans=fib[n];
		add(&ans,&fib[n-1]);
		half(&ans);
		printf("Set %d:\n",cases);
		printBigInt(&ans);
	}
	return 0;
}
