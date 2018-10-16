#include<stdio.h>
#include<string.h>
typedef struct POINT{
	int x,y;
}Point;
int main(){
	int games=0;
	int i,flag,x,y;
	char chess[15][15],*ptr;
	Point K,k;
	Point Dir[16];
	Point Knight[8];
	Dir[0].x=-1,Dir[0].y=0;
	Dir[1].x=1,Dir[1].y=0;
	Dir[2].x=0,Dir[2].y=-1;
	Dir[3].x=0,Dir[3].y=1;
	Dir[4].x=-1,Dir[4].y=-1;
	Dir[5].x=-1,Dir[5].y=1;
	Dir[6].x=1,Dir[6].y=-1;
	Dir[7].x=1,Dir[7].y=1;
	Knight[0].x=-2,Knight[0].y=1;
	Knight[1].x=-2,Knight[1].y=-1;
	Knight[2].x=2,Knight[2].y=1;
	Knight[3].x=2,Knight[3].y=-1;
	Knight[4].x=1,Knight[4].y=2;
	Knight[5].x=1,Knight[5].y=-2;
	Knight[6].x=-1,Knight[6].y=2;
	Knight[7].x=-1,Knight[7].y=-2;
	for(;;){
		memset(chess,0,sizeof(chess));
		flag=1;
		for(i=2;i<10;i++){
			scanf(" ");
			fgets(chess[i]+2,10,stdin);
			if(strncmp(chess[i]+2,"........",8)) flag=0;
			if((ptr=strchr(chess[i]+2,'k'))!=NULL)
				k.x=i,k.y=ptr-chess[i];
			if((ptr=strchr(chess[i]+2,'K'))!=NULL)
				K.x=i,K.y=ptr-chess[i];
		}
		if(flag) break;
		printf("Game #%d:",++games);
		if(chess[K.x-1][K.y-1]=='p'||chess[K.x-1][K.y+1]=='p'){
			puts(" white king is in check.");
			continue;
		}
		if(chess[k.x+1][k.y-1]=='P'||chess[k.x+1][k.y+1]=='P'){
			puts(" black king is in check.");
			continue;
		}
		for(i=0;i<8;i++){
			x=K.x,y=K.y;
			do x+=Dir[i].x,y+=Dir[i].y; while(chess[x][y]=='.');
			if(i<4){
				if(chess[x][y]=='r'||chess[x][y]=='q'){
					puts(" white king is in check.");
					break;
				}
			}else{
				if(chess[x][y]=='b'||chess[x][y]=='q'){
					puts(" white king is in check.");
					break;
				}
			}
			x=k.x,y=k.y;
			do x+=Dir[i].x,y+=Dir[i].y; while(chess[x][y]=='.');
			if(i<4){
				if(chess[x][y]=='R'||chess[x][y]=='Q'){
					puts(" black king is in check.");
					break;
				}
			}else{
				if(chess[x][y]=='B'||chess[x][y]=='Q'){
					puts(" black king is in check.");
					break;
				}
			}
		}
		if(i<8) continue;
		for(i=0;i<8;i++){
			x=K.x+Knight[i].x,y=K.y+Knight[i].y;
			if(chess[x][y]=='n'){
				puts(" white king is in check.");
				break;
			}
			x=k.x+Knight[i].x,y=k.y+Knight[i].y;
			if(chess[x][y]=='N'){
				puts(" black king is in check.");
				break;
			}
		}
		if(i<8) continue;
		puts(" no king is in check.");
	}
	return 0;
}
