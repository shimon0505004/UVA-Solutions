#include<stdio.h>
int main()
{
	int n,m,i,j;
	int seq[33];
	while(scanf("%d%d",&n,&m)==2){
		if(m==0||n==0){
			puts("Boring!");
			continue;
		}
		if(m==1||n==1){
			puts("Boring!");
			continue;
		}
		seq[0]=n;
		for(i=1;!(n%m);i++)
			seq[i]=n/=m;
		if(n==1){
			printf("%d",seq[0]);
			for(j=1;j<i;j++)
				printf(" %d",seq[j]);
			puts("");
		}else puts("Boring!");
	}
	return 0;
}
