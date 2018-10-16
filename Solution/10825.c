#include<stdio.h>
int main()
{
	int M,N,i,divide,t,j;
	int ans[6];
	while(scanf("%d%d",&M,&N)&&M+N){
		t=M+1;
		divide=1;
		for(i=0;i<M;i++){
			/*printf("%d*=%d\n",divide,N);*/
			divide*=N;
			ans[i]=divide/t;
			for(j=0;j<i;j++)
				if(ans[i]==ans[j]){
					divide=0;
					break;
				}
			/*printf("%d%%=%d\n",divide,t);*/
			divide%=t;
		}
		if(divide==1){
			printf("%d",ans[0]);
			for(i=1;i<M;i++)
				printf(" %d",ans[i]);
			puts("");
		}
		else
			puts("Not found.");
	}
	return 0;
}
