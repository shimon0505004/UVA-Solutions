#include<stdio.h>
char accept(int dis[],int N,int K,int check){
	int cur,i=0;
	while(K--){
		for(cur=0;i<N&&cur+dis[i]<=check;i++)
			cur+=dis[i];
		if(i==N) return 1;
	}
	if(i<N) return 0;
	return 1;
}
int main(){
	int UBound,LBound,mid;
	int N,K,i;
	int dis[605];
	while(scanf("%d%d",&N,&K)==2){
		N++,K++;
		for(i=0;i<N;i++) scanf("%d",&dis[i]);
		LBound=0,UBound=200000;
		while(UBound>LBound+1){
			mid=(UBound+LBound)/2;
			if(accept(dis,N,K,mid)) UBound=mid;
			else LBound=mid;
		}
		printf("%d\n",UBound);
	}
	return 0;
}
