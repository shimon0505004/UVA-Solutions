#include<stdio.h>
int main(){
	int arr[21]={0,1,1,1,3,8,21,43,69,102,145,197,261,336,425,527,645,778,929,1097,1285};
	int n,cases;
	for(cases=1;scanf("%d",&n),n;cases++)
		printf("Case #%d: %d\n",cases,arr[n]);
	return 0;
}
