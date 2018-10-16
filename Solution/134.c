#include<stdio.h>
#include<ctype.h>
#include<string.h>
char Vowel[128]={0};
char *getMOD(char input[]){
	char *ptr=input,word[100];
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	if(strlen(word)!=2) return NULL;
	if(word[0]=='g'&&Vowel[word[1]]) return ptr;
	return NULL;
}
char *getBV(char input[]){
	char *ptr=input,word[100];
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	if(strlen(word)!=2) return NULL;
	if(word[0]=='b'&&Vowel[word[1]]) return ptr;
	return NULL;
}
char *getDV(char input[]){
	char *ptr=input,word[100];
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	if(strlen(word)!=2) return NULL;
	if(word[0]=='d'&&Vowel[word[1]]) return ptr;
	return NULL;
}
char *getLV(char input[]){
	char *ptr=input,word[100];
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	if(strlen(word)!=2) return NULL;
	if(word[0]=='l'&&Vowel[word[1]]) return ptr;
	return NULL;
}
char *getV(char input[]){
	char *ptr=input,word[100];
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	if(strlen(word)!=1) return NULL;
	if(Vowel[*word]) return ptr;
	return NULL;
}
char *getNVM(char input[]){
	char *ptr=input,word[100];
	int len;
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	len=strlen(word);
	if(Vowel[word[len-1]]==0) return ptr;
	return NULL;
}
char *getPREDV(char input[]){
	char *ptr=input,word[100];
	int len;
	int offset,ret;
	if(input==NULL) return NULL;
	ret=sscanf(ptr,"%s %n",word,&offset),ptr+=offset;
	if(ret<=0) return NULL;
	len=strlen(word);
	if(len!=5) return NULL;
	if(Vowel[word[0]]==0&&Vowel[word[1]]==0&&Vowel[word[2]]==1&&Vowel[word[3]]==0&&Vowel[word[4]]==1) return ptr;
	if(Vowel[word[0]]==0&&Vowel[word[1]]==1&&Vowel[word[2]]==0&&Vowel[word[3]]==0&&Vowel[word[4]]==1) return ptr;
	return NULL;
}
char *getPredstring(char input[]){
	char *ptr,*res;
	if(input==NULL) return NULL;
	ptr=input;
	ptr=getPREDV(ptr);
	if(ptr==NULL) return NULL;
	do{
		res=ptr;
		ptr=getPREDV(ptr);
	}while(ptr!=NULL);
	return res;
}
char *getPreds(char input[]){
	char *ptr,*res;
	if(input==NULL) return NULL;
	ptr=input;
	ptr=getPredstring(ptr);
	if(ptr==NULL) return NULL;
	do{
		res=ptr;
		ptr=getV(ptr);
		ptr=getPredstring(ptr);
	}while(ptr!=NULL);
	return res;
}
char *getVerbpred(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=input;
	ptr=getMOD(ptr);
	ptr=getPredstring(ptr);
	if(ptr!=NULL) return ptr;
	return NULL;
}
char *getPredname(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=input;
	ptr=getLV(ptr);
	ptr=getPredstring(ptr);
	if(ptr!=NULL) return ptr;
	ptr=input;
	ptr=getNVM(ptr);
	if(ptr!=NULL) return ptr;
	return NULL;
}
char *getPredclaim(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=input;
	ptr=getPredname(ptr);
	ptr=getBV(ptr);
	ptr=getPreds(ptr);
	if(ptr!=NULL) return ptr;
	ptr=input;
	ptr=getDV(ptr);
	ptr=getPreds(ptr);
	if(ptr!=NULL) return ptr;
	return NULL;
}
char *getStatement(char input[]){
	char *ptr=input;
	ptr=getPredname(ptr);
	ptr=getVerbpred(ptr);
	ptr=getPredname(ptr);
	if(ptr!=NULL) return ptr;
	ptr=input;
	ptr=getPredname(ptr);
	ptr=getVerbpred(ptr);
	if(ptr!=NULL) return ptr;
	return NULL;
}
char getSentence(char input[]){
	char *ptr;
	if((ptr=getStatement(input))!=NULL&&*ptr=='\0') return 1;
	if((ptr=getPredclaim(input))!=NULL&&*ptr=='\0') return 1;
	return 0;
}
char noperiod(char input[]){
	int len=strlen(input);
	char *ptr=input+len;
	while(isspace(*--ptr));
	if(*ptr=='.'){
		*ptr='\0';
		return 0;
	}
	return 1;
}
int main(){
	char input[10000],cat[1000];
	Vowel['a']=Vowel['e']=Vowel['i']=Vowel['o']=Vowel['u']=1;
	for(;;){
		*input='\0';
		while(fgets(cat,1000,stdin),*cat!='#'&&noperiod(cat))
			strcat(input,cat);
		if(*cat=='#') break;
		noperiod(cat);
		strcat(input,cat);
		if(getSentence(input)) puts("Good");
		else puts("Bad!");
	}
	return 0;
}
