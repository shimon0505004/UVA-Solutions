#include<stdio.h>
#include<string.h>
#define MOD 1000000000
struct BigNum{
	int n[10];
};
void assign(struct BigNum *dest,struct BigNum *src){
	memcpy(dest,src,sizeof(struct BigNum));
}
void add(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<10;i++)
		dest->n[i]+=src->n[i];
	for(i=0;i<9;i++){
		dest->n[i+1]+=dest->n[i]/MOD;
		dest->n[i]%=MOD;
	}
}
void printBigNum(struct BigNum *bn){
	int i;
	for(i=9;i>0&&bn->n[i]==0;i--);
	printf("%d",bn->n[i]);
	for(i--;i>=0;i--)
		printf("%.9d",bn->n[i]);
	puts("");
}
int main(){
	struct BigNum C[205][205];
	int i,j,cases,length,n_code,sum,t;
	memset(C,0,sizeof(C));
	C[0][0].n[0]=1;
	for(i=1;i<205;i++){
		C[i][0].n[0]=C[i][i].n[0]=1;
		for(j=1;j<=i/2;j++){
			assign(&C[i][j],&C[i-1][j-1]);
			add(&C[i][j],&C[i-1][j]);
			assign(&C[i][i-j],&C[i][j]);
		}
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&length);
		scanf("%d",&n_code);
		for(sum=i=0;i<n_code;i++) scanf("%d",&t),sum+=t;
		if(length-sum+1<0) puts("0");
		else printBigNum(&C[length-sum+1][n_code]);
	}
	return 0;
}
