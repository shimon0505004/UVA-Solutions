#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct WORD{
	char w[25];
	int v[26];
	int no;
};
int compar1(const void *a,const void *b){
	struct WORD *w1=(struct WORD *)a,*w2=(struct WORD *)b;
	int comp=memcmp(w1->v,w2->v,sizeof(int[26]));
	if(comp) return comp;
	return w1->no-w2->no;
}
int compar2(const void *a,const void *b){
	struct WORD *w1=(struct WORD *)a,*w2=(struct WORD *)b;
	return memcmp(w1->v,w2->v,sizeof(int[26]));
}
int main(){
	int cases,n,i,j,len,now;
	struct WORD dict[1005],test,*search;
	scanf("%d",&cases);
	while(cases--){
		memset(dict,0,sizeof(dict));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",dict[i].w);
			len=strlen(dict[i].w);
			for(j=0;j<len;j++) dict[i].v[dict[i].w[j]-'a']++;
			dict[i].no=i;
		}
		qsort(dict,n,sizeof(struct WORD),compar1);
		while(scanf("%s",test.w),*(test.w)!='E'){
			len=strlen(test.w);
			memset(test.v,0,sizeof(test.v));
			for(i=0;i<len;i++) test.v[test.w[i]-'a']++;
			printf("Anagrams for: %s\n",test.w);
			if((search=bsearch(&test,dict,n,sizeof(struct WORD),compar2))==NULL)
				printf("No anagrams for: %s\n",test.w);
			else{
				for(;search!=dict&&memcmp(search->v,test.v,sizeof(int[26]))==0;search--);
				if(memcmp(search->v,test.v,sizeof(int[26]))) search++;
				now=search-dict;
				for(i=1;now<n&&memcmp(dict[now].v,test.v,sizeof(int[26]))==0;i++,now++)
					printf("%3d) %s\n",i,dict[now].w);
			}
		}
		if(cases) puts("");
	}
	return 0;
}
