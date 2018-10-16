#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	double n,m,h_dis,v_dis;
	int row_n,row_m,col_n,col_m;
	while(scanf("%lf%lf",&n,&m)==2){
		row_n=(int)sqrt(n+0.5),row_m=(int)sqrt(m+0.5);
		col_n=n-row_n*row_n,col_m=m-row_m*row_m;
		h_dis=abs((col_n-row_n)-(col_m-row_m))/2.0;
		row_n*=3;
		if(col_n%2==0) row_n+=2;
		else row_n++;
		row_m*=3;
		if(col_m%2==0) row_m+=2;
		else row_m++;
		v_dis=abs(row_n-row_m)*sqrt(3)/6;
		printf("%.3lf\n",sqrt(v_dis*v_dis+h_dis*h_dis));
	}
	return 0;
}
