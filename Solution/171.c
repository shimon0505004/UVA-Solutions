#include<stdio.h>
#include<ctype.h>
#include<string.h>
char *get_str(char input[],char word[]){
	char cmp[100];
	int len;
	if(input==NULL) return NULL;
	sscanf(input,"%s %n",cmp,&len);
	if(strcmp(cmp,word)!=0) return NULL;
	return input+len;
}
char *get_nnn(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	if(!isdigit(*input)) return NULL;
	for(ptr=input;isdigit(*ptr);ptr++);
	if(*ptr!=' ') return NULL;
	return ptr;
}
char *get_cas(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_str(input,"CAS");
	if(ptr!=NULL) return ptr;
	ptr=get_str(input,"CHANGE");
	ptr=get_str(ptr,"AVERAGE");
	ptr=get_str(ptr,"SPEED");
	return ptr;
}
char *get_change(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_cas(input);
	ptr=get_str(ptr,"TO");
	ptr=get_nnn(ptr);
	ptr=get_str(ptr,"KMH");
	return ptr;
}
char *get_record(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_str(input,"RECORD");
	ptr=get_str(ptr,"TIME");
	return ptr;
}
char *get_time_keeping(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_record(input);
	if(ptr!=NULL) return ptr;
	ptr=get_change(input);
	return ptr;
}
char *get_signwords(char input[]){
	char *ptr,*from,*end;
	if(input==NULL) return NULL;
	from=input,end=strchr(from,'"');
	if(end==NULL) return NULL;
	if(from==end) return NULL;
	end--;
	if(*from==' '||*end==' ') return NULL;
	for(ptr=from;ptr<=end;ptr++){
		if(*ptr==' ') continue;
		if(!isupper(*ptr)&&*ptr!='.') return NULL;
		if(*ptr=='.'&&*(ptr-1)==' ') return NULL;
	}
	return end+2;
}
char *get_sign(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	if(*input!='"') return NULL;
	ptr=get_signwords(input+1);
	return ptr;
}
char *get_where(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_str(input,"AT");
	ptr=get_sign(ptr);
	return ptr;
}
char *get_when(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_str(input,"FIRST");
	if(ptr!=NULL) return ptr;
	ptr=get_str(input,"SECOND");
	if(ptr!=NULL) return ptr;
	ptr=get_str(input,"THIRD");
	return ptr;
}
char *get_direction(char input[]){
	char *ptr;
	if(input==NULL) return NULL;
	ptr=get_str(input,"RIGHT");
	if(ptr!=NULL) return ptr;
	ptr=get_str(input,"LEFT");
	return ptr;
}
char *get_how(char input[]){
	char *ptr,*tmp;
	if(input==NULL) return NULL;
	ptr=get_str(input,"KEEP");
	if(ptr!=NULL) return ptr;
	ptr=get_str(input,"GO");
	tmp=get_when(ptr);
	if(tmp!=NULL) return tmp;
	return ptr;
}
char *get_directional(char input[]){
	char *ptr,*tmp;
	if(input==NULL) return NULL;
	ptr=get_how(input);
	ptr=get_direction(ptr);
	tmp=get_where(ptr);
	if(tmp!=NULL) return tmp;
	return ptr;
}
char *get_navigational(char input[]){
	char *ptr,*res;
	if(input==NULL) return NULL;
	ptr=get_directional(input);
	if(ptr==NULL) return NULL;
	do{
		res=ptr;
		ptr=get_str(ptr,"AND");
		ptr=get_str(ptr,"THEN");
		ptr=get_directional(ptr);
	}while(ptr!=NULL);
	return res;
}
char is_instruction(char input[]){
	char *ptr;
	ptr=get_time_keeping(input);
	if(ptr!=NULL&&(*ptr=='\0'||*ptr=='\n')) return 1;
	ptr=get_navigational(input);
	if(ptr!=NULL&&(*ptr=='\0'||*ptr=='\n')) return 1;
	ptr=get_str(ptr,"AND");
	ptr=get_time_keeping(ptr);
	if(ptr!=NULL&&(*ptr=='\0'||*ptr=='\n')) return 1;
	return 0;
}
void parse_input(char input[]){
	char word[100];
	int len;
	while(sscanf(input,"%s%n",word,&len)==1&&(input+=len))
		printf(" %s",word);
	puts("");
}
int main(){
	char input[100];
	int cases;
	for(cases=1;fgets(input,100,stdin),strcmp(input,"#\n");cases++){
		printf("%3d.",cases);
		if(is_instruction(input)) parse_input(input);
		else puts(" Trap!");
	}
	return 0;
}
