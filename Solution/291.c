#include<stdio.h>
typedef struct m{
	char map[6][6];
}MAP;
int depth=0;
void run(MAP M,int go,char output[]){
	int i;
	if(depth==8)
		puts(output);
	else
		for(i=1;i<=5;i++){
			if(M.map[go][i]){
				output[++depth]=i+'0';
				M.map[go][i]=M.map[i][go]=0;
				run(M,i,output);
				M.map[go][i]=M.map[i][go]=1;
			}
		}
	depth--;
}
int main()
{
	MAP map;
	int i;
	char output[11]={0};
	memset(map.map,0,sizeof(map.map));
	map.map[1][2]=1,map.map[1][3]=1,map.map[1][5]=1;
	map.map[2][1]=1,map.map[2][3]=1,map.map[2][5]=1;
	map.map[3][1]=1,map.map[3][2]=1,map.map[3][4]=1,map.map[3][5]=1;
	map.map[4][3]=1,map.map[4][5]=1;
	map.map[5][1]=1,map.map[5][2]=1,map.map[5][3]=1,map.map[5][4]=1;
	output[0]='1';
	run(map,1,output);
	return 0;
}
