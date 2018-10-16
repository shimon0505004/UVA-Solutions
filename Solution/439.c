#include<stdio.h>
#include<string.h>
int main(){
	int map[64][64];
	int i,j,k,t;
	char knight1[3],knight2[3];
	memset(map,1,sizeof(map));
	for(i=0;i<64;i++){
		map[i][i]=0;
		if(i>=17&&i%8>0) map[i-17][i]=map[i][i-17]=1;
		if(i>=15&&i%8<7) map[i-15][i]=map[i][i-15]=1;
		if(i>=10&&i%8>1) map[i-10][i]=map[i][i-10]=1;
		if(i>=6&&i%8<6) map[i-6][i]=map[i][i-6]=1;
		if(i+6<64&&i%8>1) map[i+6][i]=map[i][i+6]=1;
		if(i+10<64&&i%8<6) map[i+10][i]=map[i][i+10]=1;
		if(i+15<64&&i%8>0) map[i+15][i]=map[i][i+15]=1;
		if(i+17<64&&i%8<7) map[i+17][i]=map[i][i+17]=1;
	}
	for(k=0;k<64;k++)
		for(i=0;i<64;i++)
			for(j=0;j<i;j++)
				if((t=map[i][k]+map[k][j])<map[i][j])
					map[i][j]=map[j][i]=t;
	while(scanf("%s%s",knight1,knight2)==2){
		int k1=(knight1[0]-'a')*8+(knight1[1]-'1'),k2=(knight2[0]-'a')*8+(knight2[1]-'1');
		printf("To get from %s to %s takes %d knight moves.\n",knight1,knight2,map[k1][k2]);
	}
	return 0;
}
