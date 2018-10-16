#include<stdio.h>
#include<string.h>
#define MODULI 1000000000
#define SIZE 9
struct BigInt{
	int n[SIZE];
};
void assign(struct BigInt *dest,struct BigInt *src){
	memcpy(dest,src,sizeof(struct BigInt));
}
void add(struct BigInt *dest,struct BigInt *src){
	int i;
	for(i=0;i<SIZE;i++)
		dest->n[i]+=src->n[i];
	for(i=0;i<SIZE-1;i++)
		dest->n[i+1]+=dest->n[i]/MODULI,dest->n[i]%=MODULI;
}
void printBigInt(struct BigInt *bn){
	int i;
	for(i=SIZE-1;i>0&&bn->n[i]==0;i--);
	printf("%d",bn->n[i]);
	for(i--;i>=0;i--)
		printf("%.9d",bn->n[i]);
	puts("");
}
int main(){
	int i,j,n;
	struct BigInt table[5005];
	memset(table,0,sizeof(table));
	table[0].n[0]=1;
	for(i=1;i<=5000;i++)
		for(j=i;j<=5000;j++)
			add(&table[j],&table[j-i]);
	while(scanf("%d",&n)==1) printBigInt(&table[n]);
	return 0;
}
