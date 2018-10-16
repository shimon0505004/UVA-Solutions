#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct CARD{
	int face;
	char suit;
}Card;
typedef struct INHAND{
	Card c[5];
}InHand;
int compar(const void *a,const void *b){
	Card *c1=(Card *)a,*c2=(Card *)b;
	return c1->face-c2->face;
}
char is_four_of_a_kind(InHand *inhand){
	int have[14]={0},i;
	for(i=0;i<5;i++)
		if(++have[inhand->c[i].face]==4) return 1;
	return 0;
}
char is_full_house(InHand *inhand){
	qsort(inhand->c,5,sizeof(Card),compar);
	if(inhand->c[0].face==inhand->c[1].face&&inhand->c[3].face==inhand->c[4].face)
		if(inhand->c[2].face==inhand->c[0].face||inhand->c[2].face==inhand->c[4].face) return 1;
	return 0;
}
char is_flush(InHand *inhand){
	int i;
	for(i=1;i<5;i++)
		if(inhand->c[i].suit!=inhand->c[i-1].suit) return 0;
	return 1;
}
char is_straight(InHand *inhand){
	int i,count;
	qsort(inhand->c,5,sizeof(Card),compar);
	if(inhand->c[0].face!=1){
		for(i=1;i<5;i++)
			if(inhand->c[i].face-inhand->c[i-1].face!=1) return 0;
		return 1;
	}else{
		count=4;
		for(i=1;i<5&&inhand->c[i].face-inhand->c[i-1].face==1;count--,i++);
		if(count==0) return 1;
		if(inhand->c[4].face!=13) return 0;
		count--;
		for(i=4;i>=0&&inhand->c[i].face-inhand->c[i-1].face==1;count--,i--);
		if(count) return 0;
		return 1;
	}
}
char is_straight_flush(InHand *inhand){
	return is_flush(inhand)&&is_straight(inhand);
}
char is_three_of_a_kind(InHand *inhand){
	int have[14]={0},i;
	for(i=0;i<5;i++)
		if(++have[inhand->c[i].face]==3) return 1;
	return 0;
}
char is_two_pair(InHand *inhand){
	int i,count=0;
	qsort(inhand->c,5,sizeof(Card),compar);
	for(i=1;i<5;i++)
		if(inhand->c[i].face==inhand->c[i-1].face) count++,i++;
	if(count==2) return 1;
	return 0;
}
char is_one_pair(InHand *inhand){
	int i,count=0;
	qsort(inhand->c,5,sizeof(Card),compar);
	for(i=1;i<5;i++)
		if(inhand->c[i].face==inhand->c[i-1].face) return 1;
	return 0;
}
void check(InHand *inhand,int statistic[]){
	if(is_straight_flush(inhand)) statistic[8]++;
	else if(is_four_of_a_kind(inhand)) statistic[7]++;
	else if(is_full_house(inhand)) statistic[6]++;
	else if(is_flush(inhand)) statistic[5]++;
	else if(is_straight(inhand)) statistic[4]++;
	else if(is_three_of_a_kind(inhand)) statistic[3]++;
	else if(is_two_pair(inhand)) statistic[2]++;
	else if(is_one_pair(inhand)) statistic[1]++;
	else statistic[0]++;
	return;
}
int main(){
	int cases;
	int i,j;
	int statistic[9];
	char card[3];
	InHand nowinhand;
	int map[128];
	Card c[25];
	map['A']=1,map['2']=2,map['3']=3,map['4']=4,map['5']=5,map['6']=6,map['7']=7;
	map['8']=8,map['9']=9,map['X']=10,map['J']=11,map['Q']=12,map['K']=13;
	scanf("%d",&cases);
	while(cases--){
		for(i=0;i<25;i++){
			scanf("%s",card);
			c[i].suit=card[1],c[i].face=map[card[0]];
		}
		memset(statistic,0,sizeof(statistic));
		for(i=0;i<5;i++){
			for(j=0;j<5;j++)
				nowinhand.c[j]=c[i*5+j];
			check(&nowinhand,statistic);
			for(j=0;j<5;j++)
				nowinhand.c[j]=c[i+j*5];
			check(&nowinhand,statistic);
		}
		printf("%d",statistic[0]);
		for(i=1;i<9;i++) printf(", %d",statistic[i]);
		puts("");
		if(cases) puts("");
	}
	return 0;
}
