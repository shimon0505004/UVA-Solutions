#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	char *s1=(char *)a,*s2=(char *)b;
	return strcmp(s1,s2);
}
int main(){
	char dict[105][25],word[25];
	int n_dict;
	char line[255],newline[255];
	char map[128],alpha[27];
	char *ptr,start;
	int len;
	int max=0,maxi;
	int i,j,length,printed;
	for(i='A';i<='Z';i++) map[i]=i-'A'+1;
	map[(int)' ']=0;
	for(i=1;i<=26;i++) alpha[i]=i+'A'-1;
	alpha[0]=' ';
	for(n_dict=0;scanf("%s",dict[n_dict]),dict[n_dict][0]!='#';n_dict++);
	qsort(dict,n_dict,sizeof(char[25]),compar);
	getchar();
	fgets(line,255,stdin);
	length=strlen(line)-1;
	line[length]=newline[length]=0;
	for(i=0;i<27;i++){
		int count=0;
		for(j=0;j<length;j++) newline[j]=alpha[(map[(int)line[j]]+i)%27];
		for(ptr=newline;sscanf(ptr,"%s%n",word,&len)==1;ptr+=len)
			if(bsearch(word,dict,n_dict,sizeof(char[25]),compar)) count++;
		if(count>max) max=count,maxi=i;
	}
	for(j=0;j<length;j++) newline[j]=alpha[(map[(int)line[j]]+maxi)%27];
	printed=start=0;
	for(ptr=newline;sscanf(ptr,"%s%n",word,&len)==1;ptr+=len){
		if(printed+strlen(word)>60){
			puts("");
			printed=printf(word);
		}else{
			if(start) putchar(' '),printed++;
			else start=1;
			printed+=printf(word);
		}
	}
	puts("");
	return 0;
}
