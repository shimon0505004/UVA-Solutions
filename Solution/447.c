#include<stdio.h>
#include<string.h>
void printMAP(char map[][25]){
	int i;
	for(i=1;i<=20;i++)
		printf("%.20s\n",map[i]+1);
}
int main(){
	int cases,years,i,j,y;
	char input[20];
	char map[2][25][25];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d ",&years);
		memset(map[0],' ',sizeof(map[0]));
		while(fgets(input,20,stdin)!=NULL&&*input!='\n'){
			int x,y;
			sscanf(input,"%d%d",&x,&y);
			map[0][x][y]='O';
		}
		puts("********************");
		for(y=0;y<years;y++){
			int now=y%2,next=(y+1)%2;
			printMAP(map[now]);
			puts("********************");
			memset(map[next],0,sizeof(map[next]));
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++)
					if(map[now][i][j]=='O'){
						map[next][i-1][j-1]++;
						map[next][i-1][j]++;
						map[next][i-1][j+1]++;
						map[next][i][j-1]++;
						map[next][i][j+1]++;
						map[next][i+1][j-1]++;
						map[next][i+1][j]++;
						map[next][i+1][j+1]++;
					}
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++){
					if(map[now][i][j]==' '){
						if(map[next][i][j]==3) map[next][i][j]='O';
						else map[next][i][j]=' ';
					}else if(map[next][i][j]==2||map[next][i][j]==3)
						map[next][i][j]='O';
					else map[next][i][j]=' ';
				}
		}
		if(cases) puts("");
	}
	return 0;
}
