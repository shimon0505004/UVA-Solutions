#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 1
#define R 2
char possible[41][20][500];
int hourglass[41][20];
char next[41][20][500];
char exist_path[20];
long long top_down[41][20][500];
int N,S,lines;
long long count_path(int row,int col,int value){
	int accumulated=value-hourglass[row][col];
	if(top_down[row][col][value]!=0) return top_down[row][col][value];
	top_down[row][col][value]=0;
	if(row==0) top_down[row][col][value]=1,exist_path[col]=1;
	else if(row>=N){
		if(col==0) top_down[row][col][value]=count_path(row-1,col,accumulated),next[row-1][col][accumulated]|=L;
		else if(col==row-N+1) top_down[row][col][value]=count_path(row-1,col-1,accumulated),next[row-1][col-1][accumulated]|=R;
		else{
			if(possible[row-1][col-1][accumulated])
				top_down[row][col][value]+=count_path(row-1,col-1,accumulated),next[row-1][col-1][accumulated]|=R;
			if(possible[row-1][col][accumulated])
				top_down[row][col][value]+=count_path(row-1,col,accumulated),next[row-1][col][accumulated]|=L;
		}
	}else{
		if(possible[row-1][col][accumulated])
			top_down[row][col][value]+=count_path(row-1,col,accumulated),next[row-1][col][accumulated]|=R;
		if(possible[row-1][col+1][accumulated])
			top_down[row][col][value]+=count_path(row-1,col+1,accumulated),next[row-1][col+1][accumulated]|=L;
	}
	return top_down[row][col][value];
}
int main(){
	int i,j,k,now;
	long long paths;
	while(scanf("%d%d",&N,&S),N+S){
		memset(possible,0,sizeof(possible));
		memset(next,0,sizeof(next));
		memset(exist_path,0,sizeof(exist_path));
		memset(top_down,0,sizeof(top_down));
		lines=2*N-1;
		for(i=0;i<lines;i++)
			for(j=0;j<abs(N-i-1)+1;j++)
				scanf("%d",&hourglass[i][j]);
		for(i=0;i<N;i++) possible[0][i][hourglass[0][i]]=1;
		for(i=1;i<N;i++)
			for(j=0;j<N-i;j++)
				for(k=0;k<=S-hourglass[i][j];k++)
					if(possible[i-1][j][k])
						possible[i][j][k+hourglass[i][j]]=1;
					else if(possible[i-1][j+1][k])
						possible[i][j][k+hourglass[i][j]]=1;
		for(i=N-1;i<2*N-2;i++)
			for(j=0;j<=i-N+1;j++){
				for(k=0;k<=S-hourglass[i+1][j];k++)
					if(possible[i][j][k])
						possible[i+1][j][k+hourglass[i+1][j]]=1;
				for(k=0;k<=S-hourglass[i+1][j+1];k++)
					if(possible[i][j][k])
						possible[i+1][j+1][k+hourglass[i+1][j+1]]=1;
			}
		paths=0;
		for(i=0;i<N;i++)
			if(possible[2*N-2][i][S])
				paths+=count_path(2*N-2,i,S);
		printf("%lld\n",paths);
		if(paths>0){
			int accumulated=0;
			for(i=0;i<N;i++)
				if(exist_path[i]){
					now=i;
					break;
				}
			printf("%d ",now);
			for(i=0;i<N-1;i++){
				accumulated+=hourglass[i][now];
				if(next[i][now][accumulated]&L) putchar('L'),now--;
				else putchar('R');
			}
			for(i=N-1;i<2*N-2;i++){
				accumulated+=hourglass[i][now];
				if(next[i][now][accumulated]&L) putchar('L');
				else putchar('R'),now++;
			}
		}
		puts("");
	}
	return 0;
}
