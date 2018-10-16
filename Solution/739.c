#include<stdio.h>
#include<string.h>
int main(){
	char name[25],c;
	char code[5],isbreak;
	char map[27]="01230120022455012623010202";
	int count,len,i;
	puts("         NAME                     SOUNDEX CODE");
	while(scanf("%s",name)==1){
		len=strlen(name);
		code[0]=map[*name-'A'];
		count=1;
		isbreak=0;
		for(i=1;i<len;i++){
			c=map[name[i]-'A'];
			if(c=='0') isbreak=1;
			else if((isbreak==1&&c==code[count-1])||c!=code[count-1]){
				code[count++]=c;
				isbreak=0;
				if(count==4) break;
			}
		}
		if(i==len) while(count<4) code[count++]='0';
		code[0]=*name;
		code[4]=0;
		printf("%9s%-25s%s\n","",name,code);
	}
	puts("                   END OF OUTPUT");
	return 0;
}
