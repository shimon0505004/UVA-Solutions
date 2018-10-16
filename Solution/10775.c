#include<stdio.h>
int main(){
	int n,i,j;
	int mgc_sqr[3][3]={{8,3,4},{1,5,9},{6,7,2}};
	int ans[3][1005],split;
	while(scanf("%d",&n),n){
		if(n%2==0){
			puts("IMPOSSIBLE");
			continue;
		}
		n/=3;
		split=(n+1)/2;
		for(i=0;i<n;i++){
			for(j=0;j<3;j++)
				ans[0][i*3+j]=mgc_sqr[0][j]+i*9;
			for(j=0;j<3;j++)
				ans[1][((split+i)%n)*3+j]=mgc_sqr[1][j]+i*9;
			if(i%2==0)
				for(j=0;j<3;j++)
					ans[2][(split-1-i/2)*3+j]=mgc_sqr[2][j]+i*9;
			else
				for(j=0;j<3;j++)
					ans[2][(n-1-i/2)*3+j]=mgc_sqr[2][j]+i*9;
		}
		n*=3;
		for(i=0;i<3;i++,puts("")){
			printf("%d",ans[i][0]);
			for(j=1;j<n;j++)
				printf(" %d",ans[i][j]);
		}
	}
	return 0;
}
