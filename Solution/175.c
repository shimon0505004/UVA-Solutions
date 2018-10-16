#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct WORD{
	char w[80];
};
struct DICT{
	struct WORD word[5000];
	int words;
};
struct PROFILE{
	int threshold;
	int inDict[30];
	int words;
};
struct TITLE{
	int inDict[130];
	int words;
};
int insert(struct WORD *w,struct DICT *d){
	int i;
	for(i=1;i<=d->words;i++)
		if(strcmp(w->w,d->word[i].w)==0) break;
	if(i<=d->words) return i;
	strcpy(d->word[++d->words].w,w->w);
	return i;
}
int search(struct WORD *w,struct DICT *d){
	int i;
	for(i=1;i<=d->words;i++)
		if(strcmp(w->w,d->word[i].w)==0) return i;
	return 0;
}
int inProf(struct PROFILE *prof,int n){
	int i,result=0;
	for(i=1;i<=prof->words;i++) if(n==prof->inDict[i]) result++;
	return result;
}
char match(struct PROFILE *prof,struct TITLE *title){
	int prev=-1,now;
	int i;
	for(i=1;i<=title->words;i++)
		if(title->inDict[i]>0&&inProf(prof,title->inDict[i])){
			if(prev<0){
				prev=i;
				continue;
			}
			now=i;
			if(title->inDict[now]==title->inDict[prev]){
				if(inProf(prof,title->inDict[now])>1) return 1;
			}else if(now-prev-1<=prof->threshold) return 1;
			prev=i;
		}
	return 0;
}
int main(){
	char type;
	struct PROFILE prof[55];
	struct TITLE title[260];
	struct DICT dict;
	struct WORD tmp_w;
	char input[100];
	int n_prof=0,n_title=0;
	int i,j;
	memset(prof,0,sizeof(prof));
	memset(title,0,sizeof(title));
	memset(&dict,0,sizeof(dict));
	while(scanf(" %c%*c",&type),type!='#'){
		if(type=='P'){
			char *ptr;
			int len;
			n_prof++;
			scanf("%d",&prof[n_prof].threshold);
			fgets(input,100,stdin);
			for(ptr=input;sscanf(ptr,"%s%n",tmp_w.w,&len)==1;ptr+=len)
				prof[n_prof].inDict[++prof[n_prof].words]=insert(&tmp_w,&dict);
		}else{
			char c;
			int nowlen=0;
			n_title++;
			memset(&tmp_w,0,sizeof(tmp_w));
			while((c=getchar())!='|'){
				if(isalpha(c)){
					tmp_w.w[nowlen++]=tolower(c);
				}else if(c==' '&&nowlen>0){
					title[n_title].inDict[++title[n_title].words]=search(&tmp_w,&dict);
					nowlen=0;
					memset(&tmp_w,0,sizeof(tmp_w));
				}
			}
			if(nowlen>0) title[n_title].inDict[++title[n_title].words]=search(&tmp_w,&dict);
		}
	}
	for(i=1;i<=n_prof;i++){
		char start=0;
		printf("%d: ",i);
		for(j=1;j<=n_title;j++){
			if(match(&prof[i],&title[j])){
				if(start) printf(",%d",j);
				else printf("%d",j),start=1;
			}
		}
		puts("");
	}
	return 0;
}
