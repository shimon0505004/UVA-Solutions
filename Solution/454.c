#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct PHRASE{
	char p[50];
	int count[128];
};
int compar(const void *a,const void *b){
	struct PHRASE *p1=(struct PHRASE *)a,*p2=(struct PHRASE *)b;
	return strcmp(p1->p,p2->p);
}
int main(){
	struct PHRASE phrase[105];
	int cases,n_phrase,i,j,len;
	char line[50];
	scanf("%d ",&cases);
	while(cases--){
		memset(phrase,0,sizeof(phrase));
		n_phrase=0;
		while(fgets(line,50,stdin)!=NULL&&*line!='\n'){
			line[strlen(line)-1]=0;
			strcpy(phrase[n_phrase].p,line);
			len=strlen(line);
			for(i=0;i<len;i++)
				if(!isspace(line[i]))
					phrase[n_phrase].count[line[i]]++;
			n_phrase++;
		}
		qsort(phrase,n_phrase,sizeof(struct PHRASE),compar);
		for(i=0;i<n_phrase;i++)
			for(j=i+1;j<n_phrase;j++)
				if(memcmp(phrase[i].count,phrase[j].count,sizeof(int[128]))==0)
					printf("%s = %s\n",phrase[i].p,phrase[j].p);
		if(cases) puts("");
	}
	return 0;
}
