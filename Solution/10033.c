#include<stdio.h>
#include<string.h>
int main(){
	int cases,count,now;
	int registers[10];
	char a,b,type;
	char instruction[1005][5];
	scanf("%d",&cases);
	while(cases--){
		memset(registers,0,sizeof(registers));
		memset(instruction,0,sizeof(instruction));
		scanf(" ");
		for(count=0;fgets(instruction[count],5,stdin)&&instruction[count][0]!='\n';count++);
		for(now=0,count=0;;){
			type=instruction[now][0]-'0',a=instruction[now][1]-'0';
			b=instruction[now][2]-'0',now++;
			count++;
			if(type==1) break;
			switch(type){
				case 2:
					registers[a]=b;
					break;
				case 3:
					registers[a]+=b;
					break;
				case 4:
					registers[a]*=b;
					break;
				case 5:
					registers[a]=registers[b];
					break;
				case 6:
					registers[a]+=registers[b];
					break;
				case 7:
					registers[a]*=registers[b];
					break;
				case 8:
					registers[a]=atoi(instruction[registers[b]]);
					break;
				case 9:
					sprintf(instruction[registers[b]],"%.3d\n",registers[a]);
					break;
				case 0:
					if(registers[b]!=0)
						now=registers[a];
			}
			registers[a]%=1000;
		}
		printf("%d\n",count);
		if(cases) puts("");
	}
	return 0;
}
