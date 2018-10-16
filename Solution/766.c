#include<stdio.h>
#include<stdlib.h>
struct POLY{
	int M;
	int a[22];
};
int GCD(int a,int b){
	a=abs(a),b=abs(b);
	while(a%b!=0){
		int temp=a%b;
		a=b,b=temp;
	}
	return b;
}
void reduce(struct POLY *p){
	int gcd=p->M;
	int i;
	for(i=0;i<22;i++)
		if(p->a[i]!=0)
			gcd=GCD(gcd,p->a[i]);
	for(i=0;i<22;i++)
		p->a[i]/=gcd;
	p->M/=gcd;
}
void divide(struct POLY *p,int n){
	p->M*=n;
	reduce(p);
}
void multiply(struct POLY *p,int n){
	int i;
	int gcd=GCD(p->M,n);
	for(i=0;i<22;i++)
		p->a[i]*=n/gcd;
	p->M/=gcd;
}
void add(struct POLY *dest,struct POLY *src){
	int gcd=GCD(dest->M,src->M),i;
	for(i=0;i<22;i++)
		dest->a[i]=dest->a[i]*(src->M/gcd)+src->a[i]*(dest->M/gcd);
	dest->M=dest->M/gcd*src->M;
	reduce(dest);
}
void printPoly(struct POLY *p,int n){
	int i;
	printf("%d",p->M);
	for(i=n;i>=0;i--)
		printf(" %d",p->a[i]);
	puts("");
}
int main(){
	struct POLY poly[21]={{0,{0}}};
	int i,j;
	int C[22][22]={{0}};
	int cases,n;
	C[0][0]=1;
	for(i=1;i<22;i++){
		C[i][0]=1;
		for(j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	poly[0].M=1,poly[0].a[1]=1;
	for(i=1;i<21;i++){
		struct POLY temp;
		poly[i].a[i+1]=1;
		poly[i].M=1;
		for(j=2;j<=i+1;j++){
			int sign=(j%2==0?1:-1);
			temp=poly[i+1-j];
			multiply(&temp,sign*C[i+1][j]);
			add(&poly[i],&temp);
		}
		divide(&poly[i],C[i+1][1]);
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		printPoly(&poly[n],n+1);
		if(cases) puts("");
	}
	return 0;
}
