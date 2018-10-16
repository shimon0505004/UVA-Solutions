#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct WORD{
	int v[26];
};
char cover(struct WORD *puzzle,struct WORD *dict){
	int i;
	for(i=0;i<26;i++) if(puzzle->v[i]<dict->v[i]) return 0;
	return 1;
}
int main(){
	struct WORD dict[1005];
	char input[15],line[20];
	int n_word=0,len,result,i;
	struct WORD puzzle;
	memset(dict,0,sizeof(dict));
	while(scanf("%s ",input),*input!='#'){
		len=strlen(input);
		if(len>7) continue;
		for(i=0;i<len;i++) dict[n_word].v[input[i]-'a']++;
		n_word++;
	}
	while(fgets(line,20,stdin),*line!='#'){
		len=strlen(line);
		memset(puzzle.v,0,sizeof(puzzle.v));
		for(i=0;i<len;i++) if(isalpha(line[i])) puzzle.v[line[i]-'a']++;
		result=0;
		for(i=0;i<n_word;i++)
			if(cover(&puzzle,&dict[i])) result++;
		printf("%d\n",result);
	}
	return 0;
}
