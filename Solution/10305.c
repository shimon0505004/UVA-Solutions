#include<stdio.h>
#include<string.h>
int main()
{
	char topo[105][105];
	int a,b,flag;
	int cases,n,i,j;
	while(scanf("%d%d",&cases,&n)&&(cases+n)){
		memset(topo,0,sizeof(topo));
		for(i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			topo[a][b]=1;
		}
		flag=0;
		for(i=1;i<=cases;){
			for(j=0;j<=cases;j++)
				if(topo[j][i]){
					i++;
					break;
				}
			if(j>cases){
				if(flag) printf(" ");
				flag=printf("%d",i);
				memset(topo[i],0,sizeof(topo[i]));
				topo[0][i]=1;
				i=1;
			}
		}
		puts("");
	}
	return 0;
}
