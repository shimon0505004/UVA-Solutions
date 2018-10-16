#include<stdio.h>
typedef struct POINT{
	int x,y;
}Point;
int dis(Point *p1,Point *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return x*x+y*y;
}
int main(){
	char map[505][505]={0};
	char type;
	Point Icon[55];
	int i,j,Icount=1,Rcount=0,count,min;
	int ans[55],d;
	Point p,UL,DR;
	while((type=getchar())!='#'){
		if(type=='I'){
			scanf("%d%d ",&Icon[Icount].x,&Icon[Icount].y);
			Icount++;
		}else if(type=='R'){
			scanf("%d%d%d%d ",&UL.x,&UL.y,&DR.x,&DR.y);
			for(i=UL.x;i<=DR.x;i++)
				for(j=UL.y;j<=DR.y;j++)
					map[i][j]='A'+Rcount;
			Rcount++;
		}else if(type=='M'){
			scanf("%d%d ",&p.x,&p.y);
			if(map[p.x][p.y]) printf("%c\n",map[p.x][p.y]);
			else{
				count=0,min=2147483647;
				for(i=1;i<Icount;i++){
					if(map[Icon[i].x][Icon[i].y]) continue;
					if((d=dis(Icon+i,&p))<min)
						min=d,ans[0]=i,count=1;
					else if(dis(Icon+i,&p)==min)
						ans[count++]=i;
				}
				for(i=0;i<count;i++)
					printf("%3d",ans[i]);
				puts("");
			}
		}
	}
	return 0;
}
