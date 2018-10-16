#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct HOLE{
	int n;
	char c;
};
int compar(const void *a,const void *b){
	struct HOLE *h1=(struct HOLE *)a,*h2=(struct HOLE *)b;
	if(h1->n!=h2->n) return h2->n-h1->n;
	return h1->c-h2->c;
}
int countsize(char map[][55],int x,int y,char c){
	int result=1;
	map[x][y]='.';
	if(map[x-1][y]==c) result+=countsize(map,x-1,y,c);
	if(map[x][y-1]==c) result+=countsize(map,x,y-1,c);
	if(map[x+1][y]==c) result+=countsize(map,x+1,y,c);
	if(map[x][y+1]==c) result+=countsize(map,x,y+1,c);
	return result;
}
int main(){
	char map[55][55];
	int x,y,i,j,count,cases;
	struct HOLE h[3025];
	for(cases=1;scanf("%d%d",&x,&y),x+y;cases++){
		memset(map,0,sizeof(map));
		for(i=1;i<=x;i++)
			scanf("%s",map[i]+1);
		count=0;
		for(i=1;i<=x;i++)
			for(j=1;j<=y;j++){
				if(map[i][j]>='A'&&map[i][j]<='Z'){
					h[count].c=map[i][j];
					h[count].n=countsize(map,i,j,map[i][j]);
					count++;
				}
			}
		qsort(h,count,sizeof(struct HOLE),compar);
		printf("Problem %d:\n",cases);
		for(i=0;i<count;i++)
			printf("%c %d\n",h[i].c,h[i].n);
	}
	return 0;
}
