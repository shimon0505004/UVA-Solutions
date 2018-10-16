#include<stdio.h>
#define max 30
const int godir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct map{
	int dir;
	int step;
};
int loop,totalstep;
void go(int y,int x,struct map M[][max],int step)
{
	int nextx=x+godir[M[y][x].dir][1];
	int nexty=y+godir[M[y][x].dir][0];
	int isloop=M[nexty][nextx].step;
	if(isloop){
		loop=step-isloop+1;
		totalstep=isloop-1;
	}
	else if(M[nexty][nextx].dir==-1)
		totalstep=step;
	else{
		M[y][x].step=step;
		go(nexty,nextx,M,step+1);
	}
}
int main()
{
	int start,i,j,h,w;
	struct map M[max][max];
	char a;
	while(scanf("%d%d%d",&h,&w,&start)==3&&(h+w+start)){
		for(i=0;i<max;i++)
			for(j=0;j<max;j++){
				M[i][j].dir=-1;
				M[i][j].step=0;
			}
		for(i=1;i<=h;i++){
			scanf(" ");
			for(j=1;j<=w;j++){
				a=getchar();
				if(a=='N')
					M[i][j].dir=0;
				else if(a=='E')
					M[i][j].dir=1;
				else if(a=='S')
					M[i][j].dir=2;
				else
					M[i][j].dir=3;
			}
		}
		loop=totalstep=0;
		go(1,start,M,1);
		if(loop)
			printf("%d step(s) before a loop of %d step(s)\n",totalstep,loop);
		else
			printf("%d step(s) to exit\n",totalstep);
	}
	return 0;
}
