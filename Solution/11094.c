#include<stdio.h>
#include<string.h>
struct INFOR{
	int parent,size;
};
struct INFOR infor[1000];
int map(int i,int j){
	return i*30+j;
}
int find_root(int node){
	if(infor[node].parent!=node) infor[node].parent=find_root(infor[node].parent);
	return infor[node].parent;
}
void link(int n1,int n2){
	infor[n2].parent=n1;
	infor[n1].size+=infor[n2].size;
}
int main(){
	int N,M,X,Y,i,j,r,max,t;
	char contient[30][30],land;
	while(scanf("%d%d ",&M,&N)==2){
		memset(contient,0,sizeof(contient));
		memset(infor,0,sizeof(infor));
		for(i=1;i<=M;i++)
			fgets(contient[i],30,stdin);
		scanf("%d%d",&X,&Y),X++;
		land=contient[X][Y];
		for(i=1;i<=M;i++){
			for(j=0;j<N;j++){
				int r=map(i,j);
				infor[r].parent=r;
				if(contient[i][j]==land)
					infor[map(i,j)].size=1;
			}
		}
		for(i=1;i<=M;i++)
			for(j=0;j<N;j++){
				int r1=find_root(map(i,j)),r2;
				if(contient[i][j]!=land) continue;
				if(contient[i-1][j]==land){
					r2=find_root(map(i-1,j));
					if(r1!=r2) link(r1,r2);
				}
				if(contient[i+1][j]==land){
					r2=find_root(map(i+1,j));
					if(r1!=r2) link(r1,r2);
				}
				if(contient[i][(j+1)%N]==land){
					r2=find_root(map(i,(j+1)%N));
					if(r1!=r2) link(r1,r2);
				}
				if(contient[i][(j+N-1)%N]==land){
					r2=find_root(map(i,(j+N-1)%N));
					if(r1!=r2) link(r1,r2);
				}
			}
		r=find_root(map(X,Y));
		infor[r].size=0;
		max=0;
		for(i=1;i<=M;i++)
			for(j=0;j<N;j++)
				if((t=infor[find_root(map(i,j))].size)>max)
					max=t;
		printf("%d\n",max);
	}
	return 0;
}
