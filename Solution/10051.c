#include<stdio.h>
struct CUBE{
	int up,down;
};
char *dir[6]={"front","back","left","right","top","bottom"};
void printAnswer(int LIS[],int prev[],int now){
	if(prev[now]!=-1) printAnswer(LIS,prev,prev[now]);
	printf("%d ",now/6+1);
	puts(dir[now%6]);
}
int main(){
	int N,i,j;
	struct CUBE cube[3005];
	int color[6];
	int prev[3005];
	int LIS[3005],max,maxi;
	int cases;
	for(cases=1;scanf("%d",&N),N;cases++){
		if(cases>1) puts("");
		for(i=0;i<N;i++){
			for(j=0;j<6;j++) scanf("%d",&color[j]),prev[6*i+j]=-1;
			cube[6*i].up=color[0],cube[6*i].down=color[1];
			cube[6*i+1].up=color[1],cube[6*i+1].down=color[0];
			cube[6*i+2].up=color[2],cube[6*i+2].down=color[3];
			cube[6*i+3].up=color[3],cube[6*i+3].down=color[2];
			cube[6*i+4].up=color[4],cube[6*i+4].down=color[5];
			cube[6*i+5].up=color[5],cube[6*i+5].down=color[4];
		}
		N*=6;
		max=1,maxi=0;
		for(i=0;i<N;i++){
			LIS[i]=1;
			for(j=0;j<i/6*6;j++){
				if(cube[i].up==cube[j].down&&LIS[i]<LIS[j]+1){
					LIS[i]=LIS[j]+1;
					prev[i]=j;
				}
			}
			if(LIS[i]>max) max=LIS[i],maxi=i;
		}
		printf("Case #%d\n",cases);
		printf("%d\n",max);
		printAnswer(LIS,prev,maxi);
	}
	return 0;
}
