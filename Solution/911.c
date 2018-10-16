#include<stdio.h>
int main(){
	int deg,n_var,ans;
	int var[105];
	int C[101][105]={{0}};
	int i,j;
	C[0][0]=1;
	for(i=1;i<=100;i++){
		C[i][0]=1;
		for(j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	while(scanf("%d%d",&deg,&n_var)==2){
		for(i=0;i<n_var;i++)
			scanf("%d",&var[i]);
		ans=1;
		for(i=0;i<n_var;i++){
			ans*=C[deg][var[i]];
			deg-=var[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
