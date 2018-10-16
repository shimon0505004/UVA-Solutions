#include<stdio.h>
#include<math.h>
int main(){
	int N,n,k,m,cases,i,j;
	double table[1005];
	double p[1005];
	scanf("%d",&N);
	for(cases=1;cases<=N;cases++){
		scanf("%d%d%d",&n,&k,&m);
		for(i=0;i<n;i++) scanf("%lf",&p[i]);
		table[1]=p[0];
		for(i=2;i<=m;i++){
			table[i]=0;
			for(j=n-1;j>=0;j--){
				table[i]*=table[i-1];
				table[i]+=p[j];
			}
		}
		printf("Case #%d: %.7lf\n",cases,pow(table[m],k));
	}
	return 0;
}
