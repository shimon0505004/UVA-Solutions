#include<stdio.h>
#include<string.h>
struct MATRIX{
	char m[45][45];
};
int n;
void multiply(struct MATRIX *a,struct MATRIX *b){
	int i,j,k;
	struct MATRIX res;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			int t=0;
			for(k=0;k<n;k++)
				t=(t+a->m[i][k]*b->m[k][j])%10;
			res.m[i][j]=t;
		}
	*a=res;
}
struct MATRIX pow_n(struct MATRIX *a,int p){
	struct MATRIX res;
	if(p==1) return *a;
	res=pow_n(a,p/2);
	multiply(&res,&res);
	if(p%2==0) return res;
	multiply(&res,a);
	return res;
}
void printMatrix(struct MATRIX *a){
	int i,j;
	for(i=0;i<n;i++,puts("")){
		printf("%hhd",a->m[i][0]);
		for(j=1;j<n;j++)
			printf(" %hhd",a->m[i][j]);
	}
}
struct MATRIX sum(int k,struct MATRIX *a){
	struct MATRIX ans,t,rem={{{0}}};
	int i,j;
	if(k==1) return *a;
	if(k%2!=0) rem=pow_n(a,k--);
	ans=pow_n(a,k/2);
	for(i=0;i<n;i++) ans.m[i][i]=(ans.m[i][i]+1)%10;
	t=sum(k/2,a);
	multiply(&ans,&t);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ans.m[i][j]=(ans.m[i][j]+rem.m[i][j])%10;
	return ans;
}
int main(){
	int k,i,j,t;
	struct MATRIX A,ans;
	while(scanf("%d%d",&n,&k),n){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&t),A.m[i][j]=(char)(t%10);
		ans=sum(k,&A);
		printMatrix(&ans);
		puts("");
	}
	return 0;
}
