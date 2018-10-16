#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
char map[128],trump;
void deal(char player[][15],char card[]){
	player[map[card[1]]][map[card[0]]]=1;
}
void play_lead(char player[][15],char trick[]){
	int i,highest;
	for(i=14;i>1;i--) if(player[0][i]||player[1][i]||player[2][i]||player[3][i]) break;
	if(i==1) puts("Impossible");
	highest=i;
	trick[0]=highest;
	if(player[trump][highest]) trick[1]=trump;
	else
		for(i=3;i>=0;i--)
			if(player[i][highest]){
				trick[1]=i;
				break;
			}
}
void play_follow(char lead_suit,char player[][15],char trick[]){
	int i,highest;
	for(i=14;i>1;i--)
		if(player[lead_suit][i]){
			trick[0]=i,trick[1]=lead_suit;
			return;
		}
	for(i=14;i>1;i--)
		if(player[trump][i]){
			trick[0]=i,trick[1]=trump;
			return;
		}
	for(i=14;i>1;i--) if(player[0][i]||player[1][i]||player[2][i]||player[3][i]) break;
	if(i==1) puts("Impossible");
	highest=i;
	for(i=3;i>=0;i--)
		if(player[i][highest]){
			trick[0]=highest,trick[1]=i;
			return;
		}
}
int main(){
	char player[5][4][15];
	char card[3],comp[3],lead,lead_suit;
	char trick[5][2];
	int heart[5];
	int i,j;
	map['2']=2,map['3']=3,map['4']=4,map['5']=5,map['6']=6,map['7']=7,map['8']=8,map['9']=9;
	map['T']=10,map['J']=11,map['Q']=12,map['K']=13,map['A']=14;
	map['C']=0,map['D']=1,map['H']=2,map['S']=3;
	while(scanf("%s",card),*card!='#'){
		memset(player,0,sizeof(player));
		memset(heart,0,sizeof(heart));
		deal(player[1],card);
		for(i=1;i<50;i++){
			scanf("%s",card);
			deal(player[(i+1)%5],card);
		}
		scanf("%s%s",card,comp);
		if(map[card[0]]>map[comp[0]]) trump=map[card[1]];
		else if(map[comp[0]]>map[card[0]]) trump=map[comp[1]];
		else trump=MAX(map[card[1]],map[comp[1]]);
		lead=1;
		for(i=0;i<10;i++){
			int now[2],win;
			play_lead(player[lead],trick[0]);
			player[lead][trick[0][1]][trick[0][0]]=0;
			lead_suit=trick[0][1];
			for(j=1;j<5;j++){
				play_follow(lead_suit,player[(lead+j)%5],trick[j]);
				player[(lead+j)%5][trick[j][1]][trick[j][0]]=0;
			}
			now[0]=trick[0][0],now[1]=trick[0][1];
			win=lead;
			for(j=1;j<5;j++){
				if(trick[j][1]==now[1]){
					if(trick[j][0]>now[0]){
						win=(lead+j)%5;
						now[0]=trick[j][0],now[1]=trick[j][1];
					}
				}else if(trick[j][1]==trump){
					win=(lead+j)%5;
					now[0]=trick[j][0],now[1]=trick[j][1];
				}
			}
			for(j=0;j<5;j++) if(trick[j][1]==2) heart[win]+=trick[j][0];
			lead=win;
		}
		for(i=0;i<5;i++) printf("%3d",heart[i]);
		puts("");
	}
	return 0;
}
