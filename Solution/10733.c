#include<stdio.h>
#include<string.h>
#define SIZE 5
#define MODULI 1000000
struct BigInt{
	int d[SIZE];
};
void initial(struct BigInt *dest,int n){
	memset(dest,0,sizeof(struct BigInt));
	dest->d[0]=n;
}
void divide(struct BigInt *dest,int n){
	int i;
	for(i=SIZE-1;i>0;i--){
		dest->d[i-1]+=(dest->d[i]%n)*MODULI;
		dest->d[i]/=n;
	}
	dest->d[0]/=n;
}
void multiply(struct BigInt *dest,int n){
	int i;
	for(i=0;i<SIZE;i++) dest->d[i]*=n;
	for(i=0;i<SIZE-1;i++) dest->d[i+1]+=dest->d[i]/MODULI,dest->d[i]%=MODULI;
}
void add(struct BigInt *dest,int n){
	int i;
	dest->d[0]+=n;
	for(i=0;dest->d[i]>=MODULI;i++)
		dest->d[i]%=MODULI,dest->d[i+1]++;
}
void printBigInt(struct BigInt *dest){
	int i;
	for(i=SIZE-1;i>0&&dest->d[i]==0;i--);
	printf("%d",dest->d[i]);
	for(i--;i>=0;i--) printf("%.6d",dest->d[i]);
	puts("");
}
int main(){
	int n,i;
	struct BigInt cube[1005];
	for(i=1;i<1000;i++){
		initial(&cube[i],i);
		multiply(&cube[i],i);
		add(&cube[i],3);
		multiply(&cube[i],i);
		add(&cube[i],12);
		multiply(&cube[i],i);
		add(&cube[i],8);
		multiply(&cube[i],i);
		multiply(&cube[i],i);
		divide(&cube[i],24);
	}
	while(scanf("%d",&n),n) printBigInt(&cube[n]);
	return 0;
}
