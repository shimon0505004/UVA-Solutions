#include<stdio.h>
#include<string.h>
#define MODULI 1000
#define SIZE 10
struct BigInt{
	int n[SIZE];
};
void multiply(struct BigInt *dest,int n){
	int i;
	for(i=0;i<SIZE;i++) dest->n[i]*=n;
	for(i=0;i<SIZE-1;i++) dest->n[i+1]+=dest->n[i]/MODULI,dest->n[i]%=MODULI;
}
void assign_int(struct BigInt *dest,int n){
	memset(dest,0,sizeof(struct BigInt));
	dest->n[0]=n;
}
void printBigInt(struct BigInt *bn){
	int i;
	for(i=SIZE-1;i>0&&bn->n[i]==0;i--);
	printf("%d",bn->n[i]);
	for(i--;i>=0;i--)
		printf("%.3d",bn->n[i]);
	puts("");
}
int main(){
	int N,D,i;
	struct BigInt a;
	while(scanf("%d%d",&N,&D),N|D){
		assign_int(&a,1);
		for(i=0;i<D;i++)
			multiply(&a,N);
		printBigInt(&a);
	}
	return 0;
}
