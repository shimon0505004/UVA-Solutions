#include<stdio.h>
#include<string.h>
#define PAIR 1
#define TRIPLE 2
int card[52],pile[16],n_card[16],n_pile;
char corr[128];
int getCard(){
	char tmp[5];
	scanf("%s",tmp);
	return corr[*tmp];
}
void swap(int *n1,int *n2){
	int temp;
	temp=*n1,*n1=*n2,*n2=temp;
}
void deal(int r,int p){
	if(r>51) return;
	pile[p]=card[r];
	n_card[p]++;
}
char match_and_deal(int now){
	char appear[14]={0},flag=0;
	int p1,p2,p3;
	int i;
	for(i=0;i<n_pile;i++) appear[pile[i]]=1;
	for(i=1;i<=5;i++)
		if(appear[11-i]&&appear[i]){
			flag=PAIR;
			break;
		}
	if(appear[11]&&appear[12]&&appear[13]) flag|=TRIPLE;
	if(flag==0) return 0;
	for(i=0;i<n_pile;i++)
		if(pile[i]>10){
			if(flag&TRIPLE){
				flag=TRIPLE;
				break;
			}
		}else if((flag&PAIR)&&appear[11-pile[i]]){
			flag=PAIR,p1=i;
			break;
		}
	if(flag==TRIPLE){
		p1=p2=p3=53;
		for(i=0;i<n_pile;i++){
			if(pile[i]==11&&i<p1) p1=i;
			else if(pile[i]==12&&i<p2) p2=i;
			else if(pile[i]==13&&i<p3) p3=i;
		}
		if(p1>p2) swap(&p1,&p2);
		if(p2>p3) swap(&p2,&p3);
		if(p1>p2) swap(&p1,&p2);
		deal(now,p1),deal(now+1,p2),deal(now+2,p3);
	}else{
		for(i=0;i<n_pile;i++)
			if(pile[i]==11-pile[p1]) break;
		p2=i;
		deal(now,p1),deal(now+1,p2);
	}
	return flag;
}
int main(){
	int i,cases=1;
	corr['#']=-1,corr['A']=1,corr['T']=10,corr['J']=11,corr['Q']=12,corr['K']=13;
	for(i='2';i<='9';i++) corr[i]=i-'0';
	for(cases=1;;cases++){
		card[0]=getCard();
		if(card[0]==-1) break;
		for(i=1;i<52;i++) card[i]=getCard();
		n_pile=0;
		memset(n_card,0,sizeof(n_card));
		for(i=0;i<52;){
			int flag=match_and_deal(i);
			if(flag==PAIR) i+=2;
			else if(flag==TRIPLE) i+=3;
			else{
				if(n_pile==16) break;
				deal(i++,n_pile++);
			}
		}
		printf("%3d:",cases);
		if(i<52) printf(" Overflowed on card no%3d\n",i+1);
		else{
			for(i=0;i<n_pile;i++) printf("%3d",n_card[i]);
			puts("");
		}
	}
	return 0;
}
