#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
struct FIELD{
	int s_x,s_y,e_x,e_y,s;
};
int main(){
	struct FIELD move[105],next;
	char occupied[1005][1005];
	int n_game,h,w,n_move;
	int i,j,k,t,s;
	scanf("%d",&n_game);
	while(n_game--){
		memset(occupied,0,sizeof(occupied));
		scanf("%d%d%d",&h,&w,&n_move);
		for(i=0;i<n_move;i++){
			scanf("%d%d",&move[i].s_x,&move[i].s_y);
			move[i].s=MIN(h-move[i].s_x,w-move[i].s_y)+1;
			for(j=0;j<i;j++)
				if(move[j].e_x>=move[i].s_x&&move[j].e_y>=move[i].s_y)
					if((t=MAX(move[j].s_x-move[i].s_x,move[j].s_y-move[i].s_y))<move[i].s)
						move[i].s=t;
			move[i].e_x=move[i].s_x+move[i].s-1,move[i].e_y=move[i].s_y+move[i].s-1;
			for(j=move[i].s_x;j<=move[i].e_x;j++)
				for(k=move[i].s_y;k<=move[i].e_y;k++)
					occupied[j][k]=1;
		}
		next.s=0;
		for(i=1;h-i+1>=next.s&&i<=h;i++)
			for(j=1;w-j+1>=next.s&&j<=w;j++){
				if(occupied[i][j]) continue;
				s=MIN(h-i,w-j)+1;
				for(k=0;k<n_move;k++){
					if(move[k].e_x>=i&&move[k].e_y>=j)
						if((t=MAX(move[k].s_x-i,move[k].s_y-j))<s) s=t;
					if(s<=next.s) break;
				}
				if(s>next.s) next.s_x=i,next.s_y=j,next.s=s;
			}
		if(next.s==0) puts("game over");
		else printf("%d %d %d\n",next.s_x,next.s_y,next.s);
	}
	return 0;
}
