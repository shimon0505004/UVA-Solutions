#include<stdio.h>
#include<string.h>
int main(){
	int T,cases;
	int A,B,C,N,M;
	int count[10005];
	int res,i;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		int t,prev,now;
		scanf("%d%d%d%d%d",&A,&B,&C,&M,&N);
		memset(count,0,sizeof(count));
		count[0]=1;
		prev=A%M,t=prev,count[t]++;
		for(i=1;i<N;i++){
			now=(prev*B+C+1)%M;
			t=(t+now)%M,count[t]++;
			prev=now;
		}
		res=0;
		for(i=0;i<M;i++) res+=count[i]*(count[i]-1)/2;
		printf("Case %d: %d\n",cases,res);
	}
	return 0;
}
