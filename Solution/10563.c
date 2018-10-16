#include<stdio.h>
#include<string.h>
int cal_len(char map[][85],int x,int y,char alpha){
	int len,i;
	switch(alpha){
		case 'A':
			for(len=1;;len++){
				for(i=0;i<=len;i++){
					if(map[x+len][y+i]!='?') return len;
					if(map[x+i][y+len]!='?') return len;
					if(map[x+i][y+len+1]==alpha) return len;
				}
				if(map[x+len][y-1]==alpha) return len;
				if(map[x-1][y+len]==alpha) return len;
			}
		case 'B':
			for(len=1;;len++){
				if(map[x][y+len]=='?'&&map[x-1][y+len]!='A'&&map[x][y+len+1]!='A') return len;
				for(i=0;i<=len;i++){
					if(map[x+len][y+i]!='?') return len;
					if(map[x+i][y+len]!='?') return len;
					if(map[x+i][y+len+1]==alpha) return len;
				}
				if(map[x+len][y-1]==alpha) return len;
				if(map[x-1][y+len]==alpha) return len;
			}
		case 'C':
			for(len=1;;len++){
				if(map[x][y+len]=='?'&&map[x-1][y+len]!='A'&&map[x][y+len+1]!='A') return len;
				if(map[x][y+len]=='?'&&map[x-1][y+len]!='B'&&map[x][y+len+1]!='B') return len;
				for(i=0;i<=len;i++){
					if(map[x+len][y+i]!='?') return len;
					if(map[x+i][y+len]!='?') return len;
					if(map[x+i][y+len+1]==alpha) return len;
				}
				if(map[x+len][y-1]==alpha) return len;
				if(map[x-1][y+len]==alpha) return len;
			}
		case 'D':
			return 1;
	}
	return -1;
}
int main(){
	char map[105][85];
	int r,c,i,j,len,k,l;
	char alpha,start=0;
	while(scanf("%d%d",&r,&c),r|c){
		if(start) puts("");
		else start=1;
		for(i=1;i<=r;i++) scanf("%s",map[i]+1);
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				if(map[i][j]!='?') continue;
				for(alpha='A';alpha<='D';alpha++) if(map[i][j-1]!=alpha&&map[i-1][j]!=alpha&&map[i][j+1]!=alpha) break;
				len=cal_len(map,i,j,alpha);
				for(k=0;k<len;k++)
					for(l=0;l<len;l++)
						map[i+k][j+l]=alpha;
			}
		}
		for(i=1;i<=r;i++) puts(map[i]+1);
	}
	return 0;
}
