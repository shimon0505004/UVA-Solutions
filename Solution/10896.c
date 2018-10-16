#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct WORD{
	char word[18];
	int len;
	char head;
};
int compar(const void *a,const void *b){
	struct WORD *w1=(struct WORD *)a,*w2=(struct WORD *)b;
	return w1->len-w2->len;
}
int compar2(const void *a,const void *b){
	return *((char *)a)-*((char *)b);
}
int main(){
	int cases,i,count,tmp;
	char input[75],*ptr,head;
	char ans[26];
	int anscount;
	struct WORD w[35],decryp;
	scanf("%d ",&cases);
	while(cases--){
		fgets(input,75,stdin);
		count=0;
		for(ptr=input;sscanf(ptr,"%s%n",w[count].word,&tmp)==1;ptr+=tmp,count++){
			w[count].len=strlen(w[count].word);
			w[count].head=*(w[count].word);
			for(i=0;i<w[count].len;i++)
				w[count].word[i]=(w[count].word[i]+26-w[count].head)%26+'a';
		}
		qsort(w,count,sizeof(struct WORD),compar);
		scanf("%s ",decryp.word);
		decryp.len=strlen(decryp.word);
		decryp.head=*(decryp.word);
		for(i=0;i<decryp.len;i++)
			decryp.word[i]=(decryp.word[i]+26-decryp.head)%26+'a';
		anscount=0;
		memset(ans,0,sizeof(ans));
		for(i=0;i<count;i++)
			if(strcmp(decryp.word,w[i].word)==0)
				ans[anscount++]=(w[i].head+26-decryp.head)%26+'a';
		qsort(ans,anscount,sizeof(char),compar2);
		puts(ans);
	}
	return 0;
}
