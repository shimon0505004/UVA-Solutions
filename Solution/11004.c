#include<stdio.h>
int main(){
	int N,i,j,result;
	int a[3005],b[3005],c[3005];
	int negative[100],positive[100];
	int p[100][2],n_p,cases;
	for(cases=1;scanf("%d",&N),N;cases++){
		for(i=0;i<N;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
		scanf("%d",&n_p);
		for(i=0;i<n_p;i++) scanf("%d%d",&p[i][0],&p[i][1]);
		result=0;
		for(i=0;i<n_p;i++){
			positive[i]=negative[i]=0;
			for(j=0;j<N;j++){
				if(a[j]*p[i][0]+b[j]*p[i][1]+c[j]>0) positive[i]++;
				else negative[i]++;
			}
		}
		for(i=0;i<n_p;i++) result+=positive[i]*(positive[i]-1)/2+negative[i]*(negative[i]-1)/2;
		printf("Roadmap %d:\n",cases);
		printf("Negative Builders Ltd. will build %d New Roads.\n",result);
	}
	return 0;
}
