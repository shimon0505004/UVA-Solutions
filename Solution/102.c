#include<stdio.h>
#define B 0
#define C 1
#define G 2
void toanswer(int in,char *answer)
{
	char temp;
	int i;
	switch(in){
		case 0:
			temp='B';
			break;
		case 1:
			temp='C';
			break;
		case 2:
			temp='G';
			break;
	}
	for(i=0;i<5;i++)
		if(answer[i]==0){
			answer[i]=temp;
			break;
		}
}
int main()
{
	int i,j,k;
	unsigned long bin[3][3],max,needmove,total;
	char answer[5];
	while(1){
		for(i=0;i<3;i++)
			if(scanf("%lu%lu%lu",&bin[i][B],&bin[i][G],&bin[i][C])==EOF)
				return 0;
		total=0;
		for(i=0;i<3;i++)
			total+=bin[i][B]+bin[i][C]+bin[i][G];
		max=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++){
				if(j==i) continue;
				if(bin[0][i]+bin[1][j]+bin[2][3-i-j]>max){
					max=bin[0][i]+bin[1][j]+bin[2][3-i-j];
					for(k=0;k<5;k++)
						answer[k]=0;
					toanswer(i,answer);
					toanswer(j,answer);
					toanswer(3-i-j,answer);
					needmove=total-max;
				}
			}
		printf("%s %lu\n",answer,needmove);
		
	}		
	return 0;
}

