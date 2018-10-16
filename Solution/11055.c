#include<stdio.h>
int main(){
	int n,i,j;
	int array[2][1000];
	char flag;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++) scanf("%d",&array[0][i]);
		flag=0;
		for(i=1;i<n;i++){
			int prev=(i+1)&1,now=i&1,diff;
			scanf("%d",&array[now][0]);
			diff=array[now][0]-array[prev][0];
			for(j=1;j<n;j++){
				scanf("%d",&array[now][j]);
				if(flag==0&&array[now][j]-array[prev][j]!=diff)
					flag=1;
			}
		}
		if(flag==0) puts("homogeneous");
		else puts("not homogeneous");
	}
	return 0;
}
