#include<stdio.h>
int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k),n+m+k){
		if(m&1) puts("Keka");
		else puts("Gared");
	}
	return 0;
}
