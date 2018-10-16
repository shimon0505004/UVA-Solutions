#include<stdio.h>
#include<string.h>
struct POINT{
	int x,y;
};
int main(){
	char bitmap[32][33],dir;
	int cases,i,T;
	struct POINT p;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d",&p.x,&p.y);
		memset(bitmap,'.',sizeof(bitmap));
		while((dir=getchar())!='.'){
			switch(dir){
				case 'N':
					bitmap[p.y++][p.x]='X';
					break;
				case 'E':
					bitmap[p.y-1][p.x++]='X';
					break;
				case 'W':
					bitmap[p.y][--p.x]='X';
					break;
				case 'S':
					bitmap[--p.y][p.x-1]='X';
					break;
			}
		}
		printf("Bitmap #%d\n",cases);
		for(i=0;i<32;i++) bitmap[i][32]=0;
		for(i=31;i>=0;i--)
			puts(bitmap[i]);
		puts("");
	}
	return 0;
}
