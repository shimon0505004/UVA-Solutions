#include<stdio.h>
#include<string.h>
#define EMPTY 1
#define BLACK 2
struct BLOCK{
	char type;
	int no;
};
void printPuzzle(struct BLOCK block[][30],int h,int w[]){
	int i,j;
	if(w[1]){
		if(block[1][1].type) putchar('+');
		else putchar(' ');
		for(i=1;i<=w[1];i++)
			if(block[1][i].type) printf("+++++");
			else{
				printf("    ");
				if(block[1][i+1].type) putchar('+');
				else putchar(' ');
			}
	}
	puts("");
	for(i=1;i<=h;i++){
		if(w[i]){
			if(block[i][1].type) putchar('+');
			else putchar(' ');
			for(j=1;j<=w[i];j++){
				if(block[i][j].no) printf("%.3d ",block[i][j].no);
				else if(block[i][j].type==BLACK) printf("++++");
				else printf("    ");
				if(block[i][j].type||block[i][j+1].type) putchar('+');
				else putchar(' ');
			}
		}
		puts("");
		if(w[i]){
			if(block[i][1].type) putchar('+');
			else putchar(' ');
			for(j=1;j<=w[i];j++){
				if(block[i][j].type==BLACK) printf("++++");
				else printf("    ");
				if(block[i][j].type||block[i][j+1].type) putchar('+');
				else putchar(' ');
			}
		}
		puts("");
		if(w[i]||w[i+1]){
			int maxw=w[i];
			if(w[i+1]>maxw) maxw=w[i+1];
			if(block[i][1].type||block[i+1][1].type) putchar('+');
			else putchar(' ');
			for(j=1;j<=maxw;j++){
				if(block[i][j].type||block[i+1][j].type) printf("+++++");
				else{
					printf("    ");
					if(block[i][j+1].type||block[i+1][j+1].type) putchar('+');
					else putchar(' ');
				}
			}
		}
		puts("");
	}
}
char dfs(struct BLOCK block[][30],int x,int y,int h,int w,char visit[][30]){
	visit[x][y]=1;
	if(block[x][y].type) return 1;
	if(x==1||x==h) return 0;
	if(y==1||y==w) return 0;
	if(visit[x-1][y]==0) if(dfs(block,x-1,y,h,w,visit)==0) return 0; 
	if(visit[x][y-1]==0) if(dfs(block,x,y-1,h,w,visit)==0) return 0;
	if(visit[x+1][y]==0) if(dfs(block,x+1,y,h,w,visit)==0) return 0;
	if(visit[x][y+1]==0) if(dfs(block,x,y+1,h,w,visit)==0) return 0;
	return 1;
}
int main(){
	int h,w,i,j,seq,max_w[30];
	char visit[30][30];
	struct BLOCK block[30][30];
	while(scanf("%d%d",&h,&w),h|w){
		memset(block,0,sizeof(block));
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				scanf(" %c",&(block[i][j].type));
				block[i][j].type='1'-block[i][j].type;
			}
		}
		seq=0;
		memset(max_w,0,sizeof(max_w));
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				memset(visit,0,sizeof(visit));
				if(block[i][j].type==EMPTY){
					if(block[i][j+1].type==EMPTY&&block[i][j-1].type!=EMPTY)
						block[i][j].no=++seq;
					else if(block[i+1][j].type==EMPTY&&block[i-1][j].type!=EMPTY)
						block[i][j].no=++seq;
					max_w[i]=j;
				}else if(block[i][j].type==0)
					if(dfs(block,i,j,h,w,visit)) block[i][j].type=BLACK;
			}
		}
		printPuzzle(block,h,max_w);
		puts("");
	}
	return 0;
}
