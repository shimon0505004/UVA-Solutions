#include<stdio.h>
#include<string.h>
struct bowl{
	int throw1,throw2,throw3;
	char isspare,isstrike,isthrew;
};
int main()
{
	char bowl[60],*t;
	struct bowl B[13];
	int score,count,i;
	while(fgets(bowl,60,stdin)!=NULL){
		if(*bowl=='G') break;
		memset(B,0,sizeof(B));
		count=0;
		for(t=bowl;*t!='\n';t++){
			if(*t==' ') continue;
			if(B[count].isthrew){
				if(*t=='/'){
					B[count].throw2=10-B[count].throw1;
					B[count].isspare=1;
				}else
					B[count].throw2=*t-'0';
				count++;
			}else{
				if(*t=='X'){
					B[count].throw1=10;
					B[count].isstrike=1;
					count++;
				}else{
					B[count].throw1=*t-'0';
					B[count].isthrew=1;
				}
			}
		}
		score=0;
		for(i=0;i<10;i++){
			score+=B[i].throw1+B[i].throw2;
			if(B[i].isspare) score+=B[i+1].throw1;
			else if(B[i].isstrike){
				if(B[i+1].isstrike)
					score+=B[i+1].throw1+B[i+2].throw1;
				else
					score+=B[i+1].throw1+B[i+1].throw2;
			}
		}
		printf("%d\n",score);
	}
	return 0;
}
