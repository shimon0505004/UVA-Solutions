#include<stdio.h>
#include<string.h>
#define MODULI 10000000
struct BigNum{
	int n[50];
};
void assign(struct BigNum *dest,struct BigNum *src){
	memcpy(dest,src,sizeof(struct BigNum));
}
void assign_int(struct BigNum *dest,int n){
	memset(dest,0,sizeof(struct BigNum));
	dest->n[0]=n;
}
void add(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<30;i++) dest->n[i]+=src->n[i];
}
void subtract(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=0;i<30-1;i++){
		dest->n[i]-=src->n[i];
		if(dest->n[i]<0) dest->n[i]+=MODULI,dest->n[i+1]--;
	}
	dest->n[30-1]-=src->n[30-1];
}
void multiply(struct BigNum *dest,struct BigNum *src){
	long long res[30]={0};
	int i,j;
	for(i=0;i<30;i++)
		for(j=0;j+i<30;j++)
			res[i+j]+=(long long)dest->n[i]*src->n[j];
	for(i=0;i<30-1;i++){
		res[i+1]+=res[i]/MODULI;
		res[i]%=MODULI;
	}
	for(i=0;i<30;i++) dest->n[i]=(int)res[i];
}
void multiply_int(struct BigNum *dest,int n){
	int i;
	for(i=0;i<30;i++) dest->n[i]*=n;
	for(i=0;i<30-1;i++){
		dest->n[i+1]+=dest->n[i]/MODULI;
		dest->n[i]%=MODULI;
	}
}
void divide_int(struct BigNum *dest,int n){
	int i;
	for(i=30-1;i>0;i--){
		dest->n[i-1]+=(dest->n[i]%n)*MODULI;
		dest->n[i]/=n;
	}
	dest->n[0]/=n;
}
void pow_n(struct BigNum *dest,int p){
	struct BigNum n,res;
	int i;
	memset(&res,0,sizeof(res));
	n=*dest,res.n[0]=1;
	for(i=1;i<=p;i<<=1){
		if(i&p) multiply(&res,&n);
		multiply(&n,&n);
	}
	assign(dest,&res);
}
void printBigNum(struct BigNum *bn){
	int i;
	for(i=30-1;i>0&&bn->n[i]==0;i--);
	printf("%d",bn->n[i--]);
	for(;i>=0;i--) printf("%.7d",bn->n[i]);
	puts("");
}
int main(){
	struct BigNum ans,tmp;
	int A,N;
	while(scanf("%d%d",&N,&A)==2){
		if(A==0){
			puts("0");
			continue;
		}
		if(A==1){
			printf("%d\n",N*(N+1)/2);
			continue;
		}
		assign_int(&ans,A);
		pow_n(&ans,N+2);
		multiply_int(&ans,N);
		assign_int(&tmp,A);
		add(&ans,&tmp);
		assign_int(&tmp,A);
		pow_n(&tmp,N+1);
		multiply_int(&tmp,N+1);
		subtract(&ans,&tmp);
		divide_int(&ans,(A-1)*(A-1));
		printBigNum(&ans);
		assign_int(&ans,A);
	}
	return 0;
}
