#include<stdio.h>
#include<string.h>
struct PIECES{
	char p[30][30];
	int top,left,bottom,right;
};
int h,w;
void putPiece(char src[][30],int x,int y,char puzzle[][300]){
	int i;
	for(i=0;i<h;i++)
		memcpy(puzzle[x+i]+y,src[i],sizeof(char[w]));
}
int main(){
	char puzzle[300][300];
	char visit[105];
	int neigh[30][30];
	struct PIECES p[105];
	int cases,dim,i,j,k,ps,left;
	scanf("%d",&cases);
	while(cases--){
		memset(visit,0,sizeof(visit));
		memset(neigh,0,sizeof(neigh));
		memset(puzzle,0,sizeof(puzzle));
		scanf("%d%d%d%*c",&dim,&h,&w);
		ps=dim*dim;
		for(i=0;i<ps;i++){
			for(j=0;j<h;j++) fgets(p[i].p[j],30,stdin);
			scanf("%d%d%d%d%*c%*c",&p[i].top,&p[i].left,&p[i].bottom,&p[i].right);
		}
		for(i=0;i<dim;i++){
			for(j=0,left=0;j<dim;j++){
				for(k=0;k<ps;k++){
					if(visit[k]) continue;
					if(neigh[i][j]==p[k].top&&left==p[k].left){
						visit[k]=1;
						putPiece(p[k].p,i*h,j*w,puzzle);
						left=-p[k].right;
						neigh[i+1][j]=-p[k].bottom;
						break;
					}
				}
			}
		}
		for(i=0;i<h*dim;i++) puts(puzzle[i]);
		if(cases) puts("");
	}
	return 0;
}
