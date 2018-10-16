#include<stdio.h>
#define N 0
#define E 1
#define S 2
#define W 3
int main()
{
	int Wd,Ht,inX,inY,i,j,n=0,flag,isLost,len,scentX[100],scentY[100],skip;
	char face,move,dire[5]="NESW",commands[150];
	scanf("%d%d",&Wd,&Ht);
	for(i=0;i<100;i++)
		scentX[i]=scentY[i]=-1;
	while(scanf("%d%d%*c%c%*c%s",&inX,&inY,&face,commands)!=EOF){
		for(i=0;i<4;i++)
			if(dire[i]==face)
				flag=i;
		len=strlen(commands);
		for(i=0;i<len;i++){
			move=commands[i];
			isLost=0;
			skip=0;
			switch(move){
				case 'R':
					flag=(flag+1)%4;
					break;
				case 'L':
					flag=(flag+3)%4;
					break;
				case 'F':
					switch(flag){
						case 0:
							if(inY+1>Ht){
								for(j=0;j<100;j++)
									if(scentX[j]==inX&&scentY[j]==inY){
										skip=1;
										break;
									}
								if(skip) break;
								isLost=1;
								scentX[n]=inX;
								scentY[n]=inY;
								n++;
							}
							else
								inY++;
							break;
						case 1:
							if(inX+1>Wd){
								for(j=0;j<100;j++)
									if(scentX[j]==inX&&scentY[j]==inY){
										skip=1;
										break;
									}
								if(skip) break;
								isLost=1;
								scentX[n]=inX;
								scentY[n]=inY;
								n++;
							}
							else
								inX++;
							break;
						case 2:
							if(inY-1<0){
								for(j=0;j<100;j++)
									if(scentX[j]==inX&&scentY[j]==inY){
										skip=1;
										break;
									}
								if(skip) break;
								isLost=1;
								scentX[n]=inX;
								scentY[n]=inY;
								n++;
							}
							else
								inY--;
							break;
						case 3:
							if(inX-1<0){
								for(j=0;j<100;j++)
									if(scentX[j]==inX&&scentY[j]==inY){
										skip=1;
										break;
									}
								if(skip) break;
								isLost=1;
								scentX[n]=inX;
								scentY[n]=inY;
								n++;
							}
							else
								inX--;
							break;
					}
					break;
			}
			if(isLost) break;
		}
		printf("%d %d %c%s\n",inX,inY,dire[flag],isLost==1?" LOST":"");
	}
	return 0;
}


