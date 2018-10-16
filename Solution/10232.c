#include<stdio.h>
const int C[32]={0,31,496,4991,36456,206367,942648,3572223,11460948,31621023,75973188,160645503,301766028,508019103,773201628,1073741823,1374282018,1639464543,1845717618,1986838143,2071510458,2115862623,2136022698,2143911423,2146540998,2147277279,2147447190,2147478655,2147483150,2147483615,2147483646,2147483647};
int C_N_M[32][32]={0};
void B_n(int *result,int pos,int n_of_1){
	int i;
	if(n_of_1==0) return;
	for(i=n_of_1;i<32;i++) if(C_N_M[i][n_of_1]>=pos) break;
	pos-=C_N_M[i-1][n_of_1];
	*result+=1<<(i-1);
	B_n(result,pos,n_of_1-1);
}
int main()
{
	int n,i,j,n_of_1,n_of_p,result;
	C_N_M[1][0]=C_N_M[1][1]=1;
	for(i=2;i<32;i++){
		C_N_M[i][0]=1;
		for(j=i;j>0;j--)
			C_N_M[i][j]=C_N_M[i-1][j]+C_N_M[i-1][j-1];
	}
	while(scanf("%d",&n)==1){
		for(i=0;i<32;i++) if(C[i]>=n) break;
		n_of_1=i;
		n_of_p=n-C[i-1];
		result=0;
		B_n(&result,n_of_p,n_of_1);
		printf("%d\n",result);
	}
	return 0;
}
