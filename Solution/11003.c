#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int N,box[1005];
	int i,j,t,longest;
	int W[1005],capacity[1005];
	while(scanf("%d",&N),N){
		for(i=0;i<N;i++) scanf("%d%d",&W[i],&capacity[i]);
		memset(box,0,sizeof(box));
		box[0]=10000;
		longest=0;
		for(i=0;i<N;i++)
			for(j=i+1;j>=1;j--){
				if(box[j]<(t=MIN(box[j-1]-W[i],capacity[i]))){
					box[j]=t;
					if(j>longest) longest=j;
				}
			}
		printf("%d\n",longest);
	}
	return 0;
}
