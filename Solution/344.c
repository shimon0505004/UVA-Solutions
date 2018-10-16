#include<stdio.h>
int main()
{
	int num,i,j;
	int roman[101][5]={0};
	for(i=1;i<=100;i++){
		for(j=0;j<5;j++)
			roman[i][j]=roman[i-1][j];
		switch(i%10){
			case 3:
			case 8:
				roman[i][0]++;
			case 2:
			case 7:
				roman[i][0]++;
			case 1:
			case 6:
			case 4:
			case 9:
				roman[i][0]++;
		}
		if((i%10)>=4&&(i%10)<=8)
			roman[i][1]++;
		else if((i%10)==9)
			roman[i][2]++;
		switch(i/10){
			case 3:
			case 8:
				roman[i][2]++;
			case 2:
			case 7:
				roman[i][2]++;
			case 1:
			case 6:
			case 4:
			case 9:
				roman[i][2]++;
		}
		if((i/10)>=4&&(i/10)<=8)
			roman[i][3]++;
		else if(i/10==9)
			roman[i][4]++;
	}
	while(1){
		scanf("%d",&num);
		if(!num) break;
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",num,roman[num][0],roman[num][1],roman[num][2],roman[num][3],roman[num][4]);
	}
	return 0;
}
