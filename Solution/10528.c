#include<stdio.h>
#include<string.h>
char note[12][3]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
int not_major[5]={1,3,6,8,10};
int find_note(char input[]){
	int i;
	for(i=0;i<12;i++) if(strcmp(input,note[i])==0) return i;
	return -1;
}
char match_key(char used[],int offset){
	int i;
	for(i=0;i<5;i++) if(used[(offset+not_major[i])%12]) return 0;
	return 1;
}
int main(){
	char used[12];
	char line[1005],tone[3];
	int i;
	while(fgets(line,1005,stdin),strcmp(line,"END\n")){
		char *ptr,start=0;
		int len;
		memset(used,0,sizeof(used));
		for(ptr=line;sscanf(ptr,"%s%n",tone,&len)==1;ptr+=len) used[find_note(tone)]=1;
		for(i=0;i<12;i++)
			if(match_key(used,i)){
				if(start) putchar(' ');
				else start=1;
				printf(note[i]);
			}
		puts("");
	}
	return 0;
}
