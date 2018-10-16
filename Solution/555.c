#include<stdio.h>
#include<string.h>
const char *face="23456789TJQKA";
const char *suit="CDSH";
const char *dir="SWNE";
int compare(const void *card1,const void *card2)
{
	int a=(int)strchr(suit,((char*)card1)[0]),b=(int)strchr(suit,((char*)card2)[0]);
	if(a!=b)
		return a-b;
	a=(int)strchr(face,((char*)card1)[1]);
	b=(int)strchr(face,((char*)card2)[1]);
	return a-b;
}
int main()
{
	char deal[2];
	char card[4][13][3];
	char temp[3];
	int i,j,current;
	while(scanf("%s",deal)&&*deal!='#'){
		current=(strchr(dir,*deal)-dir+1)%4;
		for(i=0;i<52;i++){
			scanf("%2s",temp);
			strcpy(card[current][i/4],temp);
			current=(current+1)%4;
		}
		for(i=0;i<4;i++)
			qsort(card[i],13,sizeof(char)*3,compare);
		for(i=0;i<4;i++){
			printf("%c:",dir[i]);
			for(j=0;j<13;j++)
				printf(" %s",card[i][j]);
			puts("");
		}
	}
	return 0;
}
