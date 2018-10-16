#include<stdio.h>
#include<string.h>
#define U 0
#define L 1
#define D 2
#define R 3
char printFcurve(int,char,char);
char printRcurve(int,char,char);
char d[4]="ULDR";
char map[300][300];
int x,y,lx,ly,rx,ry;
void printDragon(char dir){
	switch(dir){
		case R:
			switch(map[x][y]){
				case 'U':
					map[x][y]='|',map[--x][++y]='R';
					break;
				case 'D':
					map[x][y]='|',map[x][++y]='R';
					break;
			}
			break;
		case L:
			switch(map[x][y]){
				case 'U':
					map[x][y]='|',map[--x][--y]='L';
					break;
				case 'D':
					map[x][y]='|',map[x][--y]='L';
			}
			break;
		case U:
			switch(map[x][y]){
				case 'L':
					map[x][y]='_',map[x][--y]='U';
					break;
				case 'R':
					map[x][y]='_',map[x][++y]='U';
					break;
			}
			break;
		case D:
			switch(map[x][y]){
				case 'L':
					map[x][y]='_',map[++x][--y]='D';
					break;
				case 'R':
					map[x][y]='_',map[++x][++y]='D';
					break;
			}
			break;
	}
	if(x<lx) lx=x;
	if(x>rx) rx=x;
	if(y<ly) ly=y;
	if(y>ry) ry=y;
}
char printRcurve(int depth,char rotate,char dir){
	if(depth>1) dir=printFcurve(depth-1,(rotate+2)%4,dir);
	if(rotate==L) dir=(dir+1)%4,printDragon(dir);
	else dir=(dir+3)%4,printDragon(dir);
	if(depth>1) dir=printRcurve(depth-1,rotate,dir);
	return dir;
}
char printFcurve(int depth,char rotate,char dir){
	if(depth>1) dir=printFcurve(depth-1,rotate,dir);
	if(rotate==L) dir=(dir+1)%4,printDragon(dir);
	else dir=(dir+3)%4,printDragon(dir);
	if(depth>1) dir=printRcurve(depth-1,(rotate+2)%4,dir);
	return dir;
}
int main(){
	int n;
	int i,j;
	while(scanf("%d",&n),n){
		memset(map,' ',sizeof(map));
		x=y=lx=ly=rx=ry=200;
		map[x][y]='R';
		printFcurve(n,L,R);
		if(map[x][y]=='U'||map[x][y]=='D') map[x][y]='|';
		else map[x][y]='_';
		for(i=lx;i<=rx;i++)
			for(j=ry+1;j>=ly&&map[i][j]==' ';j--)
				map[i][j]=0;
		for(i=lx;i<=rx;i++)
			puts(map[i]+ly);
		puts("^");
	}
	return 0;
}
