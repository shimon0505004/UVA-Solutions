#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN  305
int n_stack,maxlen;
char LCS_stack[1000][MAXN];
void push(char lcs[]){
	strcpy(LCS_stack[n_stack++],lcs);
}
void empty(){
	n_stack=0;
}
int compar(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
void findLCS(char s1[],char s2[]){
	int len1=strlen(s1),len2=strlen(s2);
	int i,j,nowlen,x,y;
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++){
			if(s1[i]==s2[j]){
				char tmp[MAXN]={0};
				for(nowlen=0,x=i,y=j;x<len1&&y<len2&&s1[x]==s2[y];nowlen++,x++,y++)
					tmp[nowlen]=s1[x];
				if(nowlen>maxlen){
					empty(),push(tmp),maxlen=nowlen;
				}else if(nowlen==maxlen)
					push(tmp);
			}
		}
}
int main(){
	char s1[MAXN],s2[MAXN];
	int i;
	char start=0;
	while(fgets(s1,MAXN,stdin)!=NULL){
		if(start) puts("");
		start=1;
		s1[strlen(s1)-1]=0;
		fgets(s2,MAXN,stdin);
		s2[strlen(s2)-1]=0;
		getchar();
		maxlen=n_stack=0;
		findLCS(s1,s2);
		if(n_stack==0){
			puts("No common sequence.");
			continue;
		}
		qsort(LCS_stack,n_stack,sizeof(char[MAXN]),compar);
		puts(LCS_stack[0]);
		for(i=1;i<n_stack;i++) if(strcmp(LCS_stack[i],LCS_stack[i-1])!=0) puts(LCS_stack[i]);
	}
	return 0;
}
