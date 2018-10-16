#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define SIZE_REDIRECT 1000
#define SIZE_SERVER 1500
#define SIZE_MX 500
struct MX{
	char from[40];
	int n_redirect;
	int to[SIZE_REDIRECT][2];
};
int compar(const void *a,const void *b){
	int *to1=(int *)a,*to2=(int *)b;
	return to1[0]-to2[0];
}
char enable[SIZE_SERVER];
int n_MX=0,n_server=0;
int find_MX(char str[],struct MX mx[]){
	int i;
	for(i=0;i<n_MX;i++) if(strcmp(mx[i].from,str)==0) return i;
	strcpy(mx[n_MX].from,str);
	mx[n_MX].n_redirect=0;
	return n_MX++;
}
int find_server(char str[],char server[][40]){
	int i;
	for(i=0;i<n_server;i++) if(strcmp(server[i],str)==0) return i;
	strcpy(server[n_server],str);
	return n_server++;
}
int find_redirect(char name[],struct MX mx[]){
	int i,j,highest=-1,priority=2147483647;
	for(i=0;i<n_MX;i++){
		if(mx[i].from[0]=='*'){
			int len1=strlen(name);
			int len2=strlen(mx[i].from)-1;
			if(strcmp(mx[i].from+1,name+len1-len2)==0)
				for(j=0;j<mx[i].n_redirect;j++)
					if(enable[mx[i].to[j][1]])
						if(mx[i].to[j][0]<priority)
							highest=mx[i].to[j][1],priority=mx[i].to[j][0];
		}else if(strcmp(name,mx[i].from)==0){
			for(j=0;j<mx[i].n_redirect;j++)
				if(enable[mx[i].to[j][1]])
					if(mx[i].to[j][0]<priority)
						highest=mx[i].to[j][1],priority=mx[i].to[j][0];
		}
	}
	return highest;
}
int main(){
	int N;
	char line[300],from[40],to[40],name[40];
	struct MX mx[SIZE_MX];
	char server[SIZE_SERVER][40];
	int prev,i_MX,priority,i_server,i_redirect;
	int i;
	scanf("%d ",&N);
	while(N--){
		fgets(line,300,stdin);
		if(isspace(line[0])){
			sscanf(line,"%d%s",&priority,to);
			i_MX=prev;
		}else{
			sscanf(line,"%s%d%s",from,&priority,to);
			i_MX=find_MX(from,mx);
		}
		i_server=find_server(to,server);
		mx[i_MX].to[mx[i_MX].n_redirect][0]=priority;
		mx[i_MX].to[mx[i_MX].n_redirect][1]=i_server;
		mx[i_MX].n_redirect++;
		enable[i_server]=1;
		prev=i_MX;
	}
	for(i=0;i<n_MX;i++) qsort(mx[i].to,mx[i].n_redirect,sizeof(int[2]),compar);
	while(fgets(line,300,stdin),*line!='X'){
		switch(*line){
			case 'A':
				sscanf(line+1,"%s",from);
				i_redirect=find_redirect(from,mx);
				printf("%s =>",from);
				if(i_redirect!=-1) printf(" %s",server[i_redirect]);
				puts("");
				break;
			case 'D':
				sscanf(line+1,"%s",name);
				i_server=find_server(name,server);
				enable[i_server]=0;
				break;
			case 'U':
				sscanf(line+1,"%s",name);
				i_server=find_server(name,server);
				enable[i_server]=1;
				break;
		}
	}
	return 0;
}
