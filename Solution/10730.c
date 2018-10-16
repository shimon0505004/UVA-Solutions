#include<stdio.h>
char isAntiarithmetic(int pos[],int n){
	int i,j;
	for(i=0;i<n-2;i++)
		for(j=i+1;j<(i+n+1)/2;j++)
			if(pos[i]<pos[j]&&pos[j]<pos[2*j-i]) return 0;
	return 1;
}
int main(){
	int pos[10005],n,i,t;
	while(scanf("%d%*c",&n),n){
		for(i=0;i<n;i++){
			scanf("%d",&t);
			pos[t]=i;
		}
		if(isAntiarithmetic(pos,n)) puts("yes");
		else puts("no");
	}
	return 0;
}
