#include<stdio.h>
#include<string.h>
char table[128][128];
void reverse(char *s){
	int len=strlen(s),i;
	char temp;
	for(i=0;i<len/2;i++)
		temp=s[i],s[i]=s[len-i-1],s[len-i-1]=temp;
}
void Cowculation(char *c1,char *c2,char oper){
	int i,j;
	switch(oper){
		case 'R':
			memmove(c2,c2+1,7);
			break;
		case 'L':
			memmove(c2+1,c2,7);
			c2[0]='V';
			break;
		case 'N':
			break;
		case 'A':
			for(i=0;i<8;i++)
				c2[i]=table[c1[i]][c2[i]];
			for(i=7;i>=0;i--)
				for(j=i;c2[j]<0;j++){
					c2[j]=-c2[j];
					c2[j+1]=table['U'][c2[j+1]];
				}
	}
}
void fill(char *s){
	int len=strlen(s),i;
	for(i=len;i<8;i++) s[i]='V';
	s[8]=0;
}
int main(){
	int cases;
	char COW1[10],COW2[10],ANS[10],operation;
	table['V']['V']='V',table['V']['U']='U',table['V']['C']='C',table['V']['D']='D';
	table['U']['V']='U',table['U']['U']='C',table['U']['C']='D',table['U']['D']=-'V';
	table['C']['V']='C',table['C']['U']='D',table['C']['C']=-'V',table['C']['D']=-'U';
	table['D']['V']='D',table['D']['U']=-'V',table['D']['C']=-'U',table['D']['D']=-'C';
	scanf("%d",&cases);
	puts("COWCULATIONS OUTPUT");
	while(cases--){
		scanf("%s%s",COW1,COW2);
		reverse(COW1),reverse(COW2);
		fill(COW2),fill(COW1);
		scanf(" %c",&operation);
		Cowculation(COW1,COW2,operation);
		scanf(" %c",&operation);
		Cowculation(COW1,COW2,operation);
		scanf(" %c",&operation);
		Cowculation(COW1,COW2,operation);
		reverse(COW2);
		scanf("%s",ANS);
		if(strcmp(ANS,COW2)==0) puts("YES");
		else puts("NO");
	}
	puts("END OF OUTPUT");
	return 0;
}
