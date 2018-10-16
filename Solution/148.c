#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EQUAL 0
#define LESS 1
#define MORE 2
typedef struct WORD{
	char w[25];
	int count[26];
}Word;
Word ans[2005];
Word dict[2005],phases[2005];
int compar(const void *a,const void *b){
	Word *w1=(Word *)a,*w2=(Word *)b;
	return strcmp(w1->w,w2->w);
}
char alphabet_compar(int a1[],int add[],int a2[]){
	int i;
	char flag=EQUAL;
	for(i=0;i<26;i++)
		if(a1[i]+add[i]>a2[i])
			return MORE;
		else if(a1[i]+add[i]<a2[i])
			if(flag==EQUAL) flag=LESS;
	return flag;
}
void add_array(int a1[],int a2[]){
	int i;
	for(i=0;i<26;i++) a1[i]+=a2[i];
}
void sub_array(int a1[],int a2[]){
	int i;
	for(i=0;i<26;i++) a1[i]-=a2[i];
}
int sentence[26];
int order[2005],words,s_count;
char anagram[25];
void printAnagram(int length){
	int i,j;
	for(i=0;i<s_count;i++)
		for(j=0;j<length;j++)
			if(strcmp(phases[i].w,dict[order[j]].w)==0) return;
	printf("%s =",anagram);
	for(i=0;i<length;i++)
		printf(" %s",dict[order[i]].w);
	puts("");
}
void dfs(int now[],int depth,int nowW){
	int i;
	for(i=nowW+1;i<words;i++){
		char comp=alphabet_compar(now,dict[i].count,sentence);
		if(comp==LESS){
			add_array(now,dict[i].count);
			order[depth]=i;
			dfs(now,depth+1,i);
			sub_array(now,dict[i].count);
		}else if(comp==EQUAL){
			order[depth]=i;
			printAnagram(depth+1);
		}
	}
}
void countLetter(Word *w){
	int i,len=strlen(w->w);
	memset(w->count,0,sizeof(w->count));
	for(i=0;i<len;i++)
		w->count[w->w[i]-'A']++;
	return;
}
int main(){
	int len;
	char *ptr;
	int i;
	int now[26];
	for(words=0;scanf("%s ",dict[words].w),*(dict[words].w)!='#';words++)
		countLetter(&(dict[words]));
	qsort(dict,words,sizeof(Word),compar);
	while(fgets(anagram,1000,stdin),*anagram!='#'){
		memset(sentence,0,sizeof(sentence));
		anagram[strlen(anagram)-1]=0;
		for(ptr=anagram,s_count=0;sscanf(ptr,"%s%n",phases[s_count].w,&len)==1;ptr+=len,s_count++){
			countLetter(&(phases[s_count]));
			for(i=0;i<26;i++)
				sentence[i]+=phases[s_count].count[i];
		}
		memset(now,0,sizeof(now));
		dfs(now,0,-1);
	}
	return 0;
}
