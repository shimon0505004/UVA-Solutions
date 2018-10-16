#include<stdio.h>
#include<string.h>
int main(){
	int cases,i,len,b[26],shares,pot,gn;
	int piece[26];
	char beans[100000],line[1000],*ptr,contestant,g;
	scanf("%d%*c%*c",&cases);
	while(cases--){
		memset(b,0,sizeof(b));
		memset(piece,0,sizeof(piece));
		fgets(beans,100000,stdin);
		beans[strlen(beans)-1]=0;
		len=strlen(beans);
		for(i=0;i<len;i++) b[beans[i]-'a']++;
		pot=shares=0;
		while(fgets(line,1000,stdin)!=NULL&&*line!='\n'){
			ptr=line;
			sscanf(ptr,"%c%*c%n",&contestant,&len);
			contestant-='A';
			ptr+=len;
			while(sscanf(ptr,"%c%*c%d%*c%n",&g,&gn,&len)==2){
				pot++;
				if(abs(b[g-'a']-gn)==1) piece[contestant]++,shares++;
				else if(b[g-'a']==gn) piece[contestant]+=2,shares+=2;
				ptr+=len;
			}
		}
		for(i=0;i<26;i++){
			if(piece[i]==0) continue;
			printf("%c %.2lf\n",i+'A',(double)pot*2*piece[i]/shares);
		}
		if(cases) puts("");
	}
	return 0;
}
