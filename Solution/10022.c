#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int row_n,row_m,col_n,col_m,m,n,result;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&m);
		m--,n--;
		row_n=(int)sqrt(n+0.5),row_m=(int)sqrt(m+0.5);
		col_n=n-row_n*row_n,col_m=m-row_m*row_m;
		result=abs(row_n-row_m);
		result+=abs(col_n/2-col_m/2);
		result+=abs((2*row_n-col_n)/2-(2*row_m-col_m)/2);
		printf("%d\n",result);
		if(cases) puts("");
	}
	return 0;
}
