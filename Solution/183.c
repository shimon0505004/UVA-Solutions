#include<stdio.h>
#include<string.h>
int cnt;
int map[205][205];
void printMap(int fx,int fy,int tx,int ty){
	int h=tx-fx+1,w=ty-fy+1,bits=map[tx][ty]-map[fx-1][ty]-map[tx][fy-1]+map[fx-1][fy-1];
	if(h<=0||w<=0) return;
	if(cnt++==50) cnt=1,puts("");
	if(bits==w*h) putchar('1');
	else if(bits==0) putchar('0');
	else{
		putchar('D');
		printMap(fx,fy,(tx+fx)/2,(ty+fy)/2);
		printMap(fx,(ty+fy)/2+1,(tx+fx)/2,ty);
		printMap((tx+fx)/2+1,fy,tx,(ty+fy)/2);
		printMap((tx+fx)/2+1,(ty+fy)/2+1,tx,ty);
	}
}
void scanMap(int fx,int fy,int tx,int ty){
	char c;
	int i,j;
	if(tx<fx||ty<fy) return;
	scanf(" %c",&c);
	if(c=='1'){
		for(i=fx;i<=tx;i++)
			for(j=fy;j<=ty;j++)
				map[i][j]=1;
	}else if(c=='0'){
		for(i=fx;i<=tx;i++)
			for(j=fy;j<=ty;j++)
				map[i][j]=0;
	}else if(c=='D'){
		scanMap(fx,fy,(tx+fx)/2,(ty+fy)/2);
		scanMap(fx,(ty+fy)/2+1,(tx+fx)/2,ty);
		scanMap((tx+fx)/2+1,fy,tx,(ty+fy)/2);
		scanMap((tx+fx)/2+1,(ty+fy)/2+1,tx,ty);
	}
}
int main(){
	char type;
	int row,col,i,j;
	while(scanf(" %c%d%d",&type,&row,&col),type!='#'){
		memset(map,0,sizeof(map));
		if(type=='B'){
			for(i=1;i<=row;i++)
				for(j=1;j<=col;j++)
					scanf("%1d",&map[i][j]);
			for(i=1;i<=row;i++){
				for(j=1;j<=col;j++) map[i][j]+=map[i][j-1];
				for(j=1;j<=col;j++) map[i][j]+=map[i-1][j];
			}
			cnt=0;
			printf("D%4d%4d\n",row,col);
			printMap(1,1,row,col);
			puts("");
		}else if(type=='D'){
			cnt=0;
			scanMap(1,1,row,col);
			printf("B%4d%4d\n",row,col);
			for(i=1;i<=row;i++)
				for(j=1;j<=col;j++){
					if(cnt++==50) cnt=1,puts("");
					printf("%d",map[i][j]);
				}
			puts("");
		}
	}
	return 0;
}
