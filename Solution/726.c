#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct FREQ{
	int c,f;
};
int compar(const void *a,const void *b){
	struct FREQ *f1=(struct FREQ *)a,*f2=(struct FREQ *)b;
	if(f1->f!=f2->f) return f1->f-f2->f;
	return f2->c-f1->c;
}
void getKnown(struct FREQ f1[]){
	char eol=0,c;
	while((c=getchar())!='\n'||eol==0){
		if(c=='\n') eol=1;
		else{
			if(isalpha(c)) f1[tolower(c)-'a'].f++;
			eol=0;
		}
	}
}
int getEncoded(char s[],struct FREQ f2[]){
	char *ptr,c;
	for(ptr=s;(c=getchar())!=EOF;ptr++){
		*ptr=c;
		if(isalpha(c)) f2[tolower(c)-'a'].f++;
	}
	return ptr-s;
}
int main(){
	struct FREQ f1[26],f2[26];
	int len,i;
	char map[26];
	char s[2000005];
	memset(f1,0,sizeof(f1)),memset(f2,0,sizeof(f2));
	for(i=0;i<26;i++) f1[i].c=f2[i].c=i;
	getKnown(f1),len=getEncoded(s,f2);
	qsort(f1,26,sizeof(struct FREQ),compar),qsort(f2,26,sizeof(struct FREQ),compar);
	for(i=0;i<26;i++) map[f2[i].c]=f1[i].c;
	for(i=0;i<len;i++){
		if(isupper(s[i]))
			putchar(map[s[i]-'A']+'A');
		else if(islower(s[i]))
			putchar(map[s[i]-'a']+'a');
		else putchar(s[i]);
	}
	return 0;
}
