#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SWAP(a,b) {Card x=a;a=b;b=x;}
typedef struct CARD{
	int face;
	char suit;
}Card;
typedef struct INHAND{
	Card c[5];
	int Val;
	int cmp[5];
}InHand;
const char message[3][20]={"Black wins.","White wins.","Tie."};
int compar(const void *a,const void *b){
	Card *c1=(Card *)a,*c2=(Card *)b;
	return c1->face-c2->face;
}
char is_four_of_a_kind(InHand *inhand){
	int have[15]={0},i;
	for(i=0;i<5;i++)
		if(++have[inhand->c[i].face]==4){
			inhand->Val=8;
			inhand->cmp[0]=inhand->c[i].face;
			return 1;
		}
	return 0;
}
char is_full_house(InHand *inhand){
	if(inhand->c[0].face==inhand->c[1].face&&inhand->c[3].face==inhand->c[4].face)
		if(inhand->c[2].face==inhand->c[0].face||inhand->c[2].face==inhand->c[4].face){
			inhand->Val=7;
			inhand->cmp[0]=inhand->c[2].face;
			return 1;
		}
	return 0;
}
char is_flush(InHand *inhand){
	int i;
	for(i=1;i<5;i++)
		if(inhand->c[i].suit!=inhand->c[i-1].suit) return 0;
	inhand->Val=6;
	return 1;
}
char is_straight(InHand *inhand){
	int i;
	for(i=1;i<5;i++)
		if(inhand->c[i].face-inhand->c[i-1].face!=1) return 0;
	inhand->Val=5;
	inhand->cmp[0]=inhand->c[4].face;
	return 1;
}
char is_straight_flush(InHand *inhand){
	if(is_flush(inhand)&&is_straight(inhand)){
		inhand->Val=9;
		return 1;
	}
	return 0;
}
char is_three_of_a_kind(InHand *inhand){
	int have[15]={0},i;
	for(i=0;i<5;i++)
		if(++have[inhand->c[i].face]==3){
			inhand->Val=4;
			inhand->cmp[0]=inhand->c[i].face;
			return 1;
		}
	return 0;
}
char is_two_pair(InHand *inhand){
	int i,count=0,have[15]={0};
	if(inhand->c[0].face!=inhand->c[1].face) inhand->cmp[2]=inhand->c[0].face;
	else if(inhand->c[2].face!=inhand->c[3].face) inhand->cmp[2]=inhand->c[2].face;
	else inhand->cmp[2]=inhand->c[4].face;
	for(i=4;i>0;i--)
		if(inhand->c[i].face==inhand->c[i-1].face) inhand->cmp[count++]=inhand->c[i].face;
	if(count==2){
		inhand->Val=3;
		return 1;
	}
	return 0;
}
char is_one_pair(InHand *inhand){
	int i,count=0;
	for(i=1;i<5;i++)
		if(inhand->c[i].face==inhand->c[i-1].face){
			SWAP(inhand->c[i],inhand->c[4]);
			SWAP(inhand->c[i-1],inhand->c[3]);
			inhand->Val=2;
			return 1;
		}
	return 0;
}
void check(InHand *inhand){
	if(is_straight_flush(inhand)) return;
	if(is_four_of_a_kind(inhand)) return;
	if(is_full_house(inhand)) return;
	if(is_flush(inhand)) return;
	if(is_straight(inhand)) return;
	if(is_three_of_a_kind(inhand)) return;
	if(is_two_pair(inhand)) return;
	if(is_one_pair(inhand)) return;
	return;
}
void basicCmp(InHand *p1,InHand *p2){
	int i;
	for(i=4;i>=0;i--)
		if(p1->c[i].face>p2->c[i].face){
			puts(message[0]);
			return;
		}else if(p1->c[i].face<p2->c[i].face){
			puts(message[1]);
			return;
		}
	puts(message[2]);
	return;
}
int main(){
	int i,j,val;
	InHand player[2];
	char card[3];
	int map[128];
	map['A']=14,map['2']=2,map['3']=3,map['4']=4,map['5']=5,map['6']=6,map['7']=7;
	map['8']=8,map['9']=9,map['T']=10,map['J']=11,map['Q']=12,map['K']=13;
	while(scanf("%s",card)==1){
		player[0].c[0].suit=card[1],player[0].c[0].face=map[card[0]];
		for(i=1;i<5;i++){
			scanf("%s",card);
			player[0].c[i].suit=card[1],player[0].c[i].face=map[card[0]];
		}
		player[0].Val=1;
		for(i=0;i<5;i++){
			scanf("%s",card);
			player[1].c[i].suit=card[1],player[1].c[i].face=map[card[0]];
		}
		player[1].Val=1;
		qsort(player[0].c,5,sizeof(Card),compar);
		qsort(player[1].c,5,sizeof(Card),compar);
		check(player);
		check(player+1);
		if(player[0].Val>player[1].Val) puts(message[0]);
		else if(player[1].Val>player[0].Val) puts(message[1]);
		else{
			val=player[1].Val;
			if(val==1||val==2||val==6){
				basicCmp(player,player+1);
			}else if(val==3){
				for(i=0;i<3;i++)
					if(player[0].cmp[i]>player[1].cmp[i]){
						puts(message[0]);
						break;
					}else if(player[0].cmp[i]<player[1].cmp[i]){
						puts(message[1]);
						break;
					}
				if(i==3) puts(message[2]);
			}else{
				if(player[0].cmp[0]>player[1].cmp[0])
					puts(message[0]);
				else if(player[0].cmp[0]<player[1].cmp[0])
					puts(message[1]);
				else puts(message[2]);
			}
		}
	}
	return 0;
}
