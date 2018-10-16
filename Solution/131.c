#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SWAP(a,b){Card c=a;a=b,b=c;}
typedef struct CARD{
	int face;
	char suit;
}Card;
typedef struct INHAND{
	Card c[5];
}InHand;
int max;
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
	if(inhand->c[0].face==1&&inhand->c[1].face==10) return 1;
	for(i=1;i<5;i++)
		if(inhand->c[i].face-inhand->c[i-1].face!=1) return 0;
	return 1;
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
void check(InHand inhand){
	if(is_straight_flush(&inhand)) max=9;
	if(max>7) return;
	if(is_four_of_a_kind(&inhand)) max=8;
	if(max>6) return;
	if(is_full_house(&inhand)) max=7;
	if(max>5) return;
	if(is_flush(&inhand)) max=6;
	if(max>4) return;
	if(is_straight(&inhand)) max=5;
	if(max>3) return;
	if(is_three_of_a_kind(&inhand)) max=4;
	if(max>2) return;
	if(is_two_pair(&inhand)) max=3;
	if(max>1) return;
	if(is_one_pair(&inhand)) max=2;
	return;
}
void push(InHand *inhand,int discard,InHand *indeck,int top){
	SWAP(inhand->c[discard],inhand->c[top]);
	inhand->c[top]=indeck->c[top];
}
void dfs(int depth,InHand *inhand,InHand *indeck){
	InHand temp;
	int i;
	if(depth==5||max==9) return;
	for(i=depth;i<5;i++){
		int j;
		temp=*inhand;
		push(&temp,i,indeck,depth);
		check(temp);
		dfs(depth+1,&temp,indeck);
	}
}
int main(){
	int i,j;
	InHand inhand,indeck;
	char card[3];
	char value[10][20]={"","highest-card","one-pair","two-pairs","three-of-a-kind","straight","flush","full-house","four-of-a-kind","straight-flush"};
	int map[128];
	map['A']=1,map['2']=2,map['3']=3,map['4']=4,map['5']=5,map['6']=6,map['7']=7;
	map['8']=8,map['9']=9,map['T']=10,map['J']=11,map['Q']=12,map['K']=13;
	while(scanf("%s",card)==1){
		printf("Hand:");
		printf(" %s",card);
		inhand.c[0].suit=card[1],inhand.c[0].face=map[card[0]];
		for(i=1;i<5;i++){
			scanf("%s",card);
			printf(" %s",card);
			inhand.c[i].suit=card[1],inhand.c[i].face=map[card[0]];
		}
		printf(" Deck:");
		for(i=0;i<5;i++){
			scanf("%s",card);
			printf(" %s",card);
			indeck.c[i].suit=card[1],indeck.c[i].face=map[card[0]];
		}
		max=1;
		check(inhand);
		dfs(0,&inhand,&indeck);
		printf(" Best hand: %s\n",value[max]);
	}
	return 0;
}
