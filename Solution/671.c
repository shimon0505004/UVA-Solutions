#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compar(const void *a,const void *b){
	char *s1=(char *)a,*s2=(char *)b;
	return strcmp(s1,s2);
}
char one_operation(char s1[],char s2[]){
	int len1=strlen(s1),len2=strlen(s2);
	int i,j;
	if(abs(len1-len2)>1) return 0;
	if(len1==len2){
		char flag=0;
		for(i=0;i<len1;i++)
			if(s1[i]!=s2[i]){
				if(flag) return 0;
				else flag=1;
			}
		return 1;
	}else{
		char flag=0;
		for(i=j=0;i<len1||j<len2;){
			if(s1[i]==s2[j]) i++,j++;
			else{
				if(flag++) return 0;
				if(len1>len2) i++;
				else j++;
			}
		}
		return 1;
	}
}
int main(){
	int cases,i;
	char dict[10005][20],sorted[10005][20];
	int n_dict;
	char word[20];
	scanf("%d",&cases);
	while(cases--){
		for(n_dict=0;scanf("%s",dict[n_dict]),dict[n_dict][0]!='#';n_dict++);
		memcpy(sorted,dict,sizeof(char[n_dict][20]));
		qsort(sorted,n_dict,sizeof(char[20]),compar);
		while(scanf("%s",word),word[0]!='#'){
			printf(word);
			if(bsearch(word,sorted,n_dict,sizeof(char[20]),compar)) puts(" is correct");
			else{
				putchar(':');
				for(i=0;i<n_dict;i++) if(one_operation(word,dict[i])) printf(" %s",dict[i]);
				puts("");
			}
		}
		if(cases) puts("");
	}
	return 0;
}
