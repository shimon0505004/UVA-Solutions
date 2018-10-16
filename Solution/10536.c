#include<stdio.h>
#include<string.h>
#define SIZE (1<<16)
#define WIN 1
#define LOSE -1
char state[SIZE];
int pins[48]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,1+2,16+32,256+512,4096+8192,4+8,64+128,1024+2048,16384+32768,1+16,2+32,4+64,8+128,256+4096,512+8192,1024+16384,2048+32768,1+2+4,16+32+64,256+512+1024,4096+8192+16384,2+4+8,32+64+128,512+1024+2048,8192+16384+32768,1+16+256,2+32+512,4+64+1024,8+128+2048,16+256+4096,32+512+8192,64+1024+16384,128+2048+32768};
char top_down(int s){
	int i;
	if(state[s]) return state[s];
	for(i=0;i<48;i++){
		if((s&pins[i])==pins[i]&&top_down(s^pins[i])==LOSE){
			return state[s]=WIN;
		}
	}
	return state[s]=LOSE;
}
int main(){
	int cases;
	int i,j;
	char line[5];
	state[0]=WIN;
	scanf("%d",&cases);
	while(cases--){
		int t=0;
		for(i=0;i<4;i++){
			scanf("%s",line);
			for(j=0;j<4;j++){
				t<<=1;
				if(line[j]=='.') t++;
			}
		}
		if(top_down(t)==WIN) puts("WINNING");
		else puts("LOSING");
	}
	return 0;
}
