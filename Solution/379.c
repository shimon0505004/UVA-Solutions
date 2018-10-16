#include<stdio.h>
#include<string.h>
struct POS{
	int x,y;
};
struct POS pos[34];
int map[11][11];
int up(int dest,int step){
	return map[pos[dest].x-step][pos[dest].y];
}
int down(int dest,int step){
	return map[pos[dest].x+step][pos[dest].y];
}
int left(int dest,int step){
	return map[pos[dest].x][pos[dest].y-step];
}
int right(int dest,int step){
	return map[pos[dest].x][pos[dest].y+step];
}
int main(){
	int cases;
	int i,j,count,peg,res,dest;
	char hi_q[34];
	memset(pos,0,sizeof(pos));
	memset(map,0,sizeof(map));
	count=0;
	for(i=2;i<=3;i++)
		for(j=4;j<=6;j++)
			map[i][j]=++count,pos[count].x=i,pos[count].y=j;
	for(i=4;i<=6;i++)
		for(j=2;j<=8;j++)
			map[i][j]=++count,pos[count].x=i,pos[count].y=j;
	for(i=7;i<=8;i++)
		for(j=4;j<=6;j++)
			map[i][j]=++count,pos[count].x=i,pos[count].y=j;
	puts("HI Q OUTPUT");
	scanf("%d",&cases);
	while(cases--){
		memset(hi_q,0,sizeof(hi_q));
		while(scanf("%d",&peg),peg) hi_q[peg]=1;
		do{
			for(dest=33;dest>0;dest--){
				if(hi_q[dest]==0){
					int mid,src;
					mid=down(dest,1),src=down(dest,2);
					if(hi_q[mid]&&hi_q[src]){
						hi_q[src]=hi_q[mid]=0;
						hi_q[dest]=1;
						break;
					}
					mid=right(dest,1),src=right(dest,2);
					if(hi_q[mid]&&hi_q[src]){
						hi_q[src]=hi_q[mid]=0;
						hi_q[dest]=1;
						break;
					}
					mid=left(dest,1),src=left(dest,2);
					if(hi_q[mid]&&hi_q[src]){
						hi_q[src]=hi_q[mid]=0;
						hi_q[dest]=1;
						break;
					}
					mid=up(dest,1),src=up(dest,2);
					if(hi_q[mid]&&hi_q[src]){
						hi_q[src]=hi_q[mid]=0;
						hi_q[dest]=1;
						break;
					}
				}
			}
		}while(dest>0);
		res=0;
		for(i=1;i<=33;i++) if(hi_q[i]) res+=i;
		printf("%d\n",res);
	}
	puts("END OF OUTPUT");
	return 0;
}
