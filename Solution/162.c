#include<stdio.h>
#include<string.h>
#define MAX 52
#define NONDEALER 0
#define DEALER 1
#define TABLE 2
#define TEMP 3
int c[4][MAX];
int n_stack[4];
void initial(){
	n_stack[0]=n_stack[1]=n_stack[2]=n_stack[3]=0;
}
void push(int index,int value){
	c[index][n_stack[index]++]=value;
}
int pop(int index){
	return c[index][--n_stack[index]];
}
char is_empty(int index){
	return n_stack[index]==0;
}
int play(int index,int value){
	int card=0,i;
	if(value==0||value==1){
		if(!is_empty(index)){
			card=pop(index);
			push(TABLE,card);
			return card;
		}
		return -1;
	}
	for(i=0;i<value&&card==0&&!is_empty(index);i++){
		card=pop(index);
		push(TABLE,card);
	}
	if(card) return card;
	if(i<value) return -1;
	return 0;
}
int main(){
	char card[3];
	int value,count,i,win;
	for(;;){
		initial();
		for(i=0;i<52;i++){
			scanf("%s",card);
			if(*card=='#') break;
			switch(card[1]){
				case 'A':
					value=4;
					break;
				case 'K':
					value=3;
					break;
				case 'Q':
					value=2;
					break;
				case 'J':
					value=1;
					break;
				default:
					value=0;
			}
			push(i&1,value);
		}
		if(i<52) break;
		count=value=0;
		for(;;){
			char seq=0;
			int now;
			while((value=play(count++&1,value))>0)
				seq=1;
			if(value<0){
				win=count&1;
				break;
			}
			if(seq){
				now=count&1;
				while(!is_empty(now))
					push(TEMP,pop(now));
				while(!is_empty(TABLE))
					push(now,pop(TABLE));
				while(!is_empty(TEMP))
					push(now,pop(TEMP));
			}
		}
		if(win==DEALER)
			printf("1 %2d\n",n_stack[DEALER]);
		else
			printf("2 %2d\n",n_stack[NONDEALER]);
	}
	return 0;
}
