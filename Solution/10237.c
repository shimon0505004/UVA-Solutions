#include<stdio.h>
int main(){
	int n,m;
	int l,i,j;
	long long bishop[33][33][60]={{{0}}};
	long long result;
	for(i=1;i<=32;i++)
		for(j=0;j<=32;j++)
			bishop[i][j][0]=1;
	for(l=1;l<=30;l++){
		for(i=1;i+l-1<=30;i++){
			int from=i,to=i+l-1;
			int rows,grids;
			if((to-from)%2==0){
				rows=((to-from)/2)*2+1;
				grids=(to+from)*((to-from)/2+1)-to;
			}else{
				rows=((to-from)/2+1)*2;
				grids=(to-1+from)*((to-from)/2+1);
			}
			bishop[from][to][1]=grids;
			for(j=2;j<=rows;j++){
				bishop[from][to][j]=2*from*bishop[from+1][to-1][j-1]+from*(from-1)*bishop[from][to-2][j-2]+bishop[from+2][to][j];
			}
		}
	}
	while(scanf("%d%d",&n,&m),n+m){
		if(m>2*n-1){
			puts("0");
			continue;
		}
		result=0;
		for(i=0;i<=m;i++)
			result+=bishop[1][n][i]*bishop[2][n][m-i];
		printf("%lld\n",result);
	}
	return 0;
}
