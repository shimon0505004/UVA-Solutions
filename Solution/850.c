#include<stdio.h>
#include<string.h>
int main(){
	int cases,lines,i,j,len;
	char map[128],c;
	char input[105][85],key[]="the quick brown fox jumps over the lazy dog";
	scanf("%d ",&cases);
	while(cases--){
		for(lines=0;fgets(input[lines],85,stdin);lines++){
			if(input[lines][0]=='\n') break;
			input[lines][strlen(input[lines])-1]=0;
		}
		for(i=0;i<lines;i++){
			if(strlen(input[i])!=43) continue;
			if(input[i][0]==' ') continue;
			if(input[i][3]!=' ') continue;
			memset(map,0,sizeof(map));
			for(j=0;j<43;j++){
				c=input[i][j];
				if(map[c]!=0&&map[c]!=key[j]) break;
				map[c]=key[j];
			}
			if(j==43) break;
		}
		if(i==lines) puts("No solution.");
		else{
			for(i=0;i<lines;i++){
				len=strlen(input[i]);
				for(j=0;j<len;j++)
					putchar(map[input[i][j]]);
				puts("");
			}
		}
		if(cases) puts("");
	}
	return 0;
}
