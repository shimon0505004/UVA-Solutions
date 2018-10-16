#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define INSERT 0
#define OVERWRITE 1
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)<(b)?(b):(a))
char map[10][11];
char mode;
int row,col;
void output(char c){
	if(mode==INSERT) memmove(map[row]+col+1,map[row]+col,sizeof(char[9-col]));
	map[row][col]=c;
	col=MIN(col+1,9);
}
char *command(char *ptr){
	char c=*ptr;
	if(c=='b')
		col=0;
	else if(c=='c')
		memset(map,' ',sizeof(map));
	else if(c=='d')
		row=MIN(row+1,9);
	else if(c=='e')
		memset(map[row]+col,0,sizeof(char[10-col]));
	else if(c=='h')
		row=col=0;
	else if(c=='i')
		mode=INSERT;
	else if(c=='l')
		col=MAX(col-1,0);
	else if(c=='o')
		mode=OVERWRITE;
	else if(c=='r')
		col=MIN(col+1,9);
	else if(c=='u')
		row=MAX(row-1,0);
	else if(c=='^')
		output('^');
	else if(isdigit(c)){
		row=c-'0';
		col=*(ptr+1)-'0';
		return ptr+2;
	}
	return ptr+1;
}
void printMAP(){
	int i;
	puts("+----------+");
	for(i=0;i<10;i++)
		printf("|%.10s|\n",map[i]);
	puts("+----------+");
}
int main(){
	int lines,cases;
	char input[500],*ptr;
	for(cases=1;scanf("%d%*c",&lines),lines;cases++){
		mode=OVERWRITE;
		row=col=0;
		memset(map,' ',sizeof(map));
		while(lines--){
			ptr=fgets(input,500,stdin);
			while(*ptr!='\n'){
				if(*ptr=='^')
					ptr=command(ptr+1);
				else{
					output(*ptr);
					ptr++;
				}
			}
		}
		printf("Case %d\n",cases);
		printMAP();
	}
	return 0;
}
