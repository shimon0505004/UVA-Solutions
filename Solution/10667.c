#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int table[105][105];
	int p,s,b,r1,r2,c1,c2;
	int i,j,k,l,size;
	scanf("%d",&p);
	while(p--){
		scanf("%d%d",&s,&b);
		memset(table,0,sizeof(table));
		while(b--){
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			for(i=r1;i<=r2;i++)
				for(j=c1;j<=c2;j++)
					table[i][j]=1;
		}
		for(i=1;i<=s;i++){
			for(j=1;j<=s;j++) table[i][j]+=table[i][j-1];
			for(j=1;j<=s;j++) table[i][j]+=table[i-1][j];
		}
		size=0;
		for(i=1;i<=s;i++)
			for(j=1;j<=s;j++)
				for(k=i;k<=s;k++)
					for(l=MAX(j,size/(k-i+1));l<=s;l++)
						if(table[k][l]-table[k][j-1]-table[i-1][l]+table[i-1][j-1]==0){
							int t=(l-j+1)*(k-i+1);
							size=MAX(size,t);
						}else break;
		printf("%d\n",size);
	}
	return 0;
}
