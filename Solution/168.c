#include<stdio.h>
#include<string.h>
int main(){
	char map[26][26],candle[26];
	char input[260],*ptr,from,to[30],check;
	char Theseus,Minotaur;
	int offset,len,i,j,step,nextmove,min;
	while(fgets(input,260,stdin),*input!='#'){
		memset(map,0,sizeof(map));
		memset(candle,0,sizeof(candle));
		for(ptr=input,check=';';check==';';ptr+=offset){
			sscanf(ptr,"%c%*c%[^;.]%c%n",&from,to,&check,&offset);
			len=strlen(to);
			for(i=0;i<len;i++)
				map[from-'A'][to[i]-'A']=i+1;
		}
		sscanf(ptr," %c %c%d",&Minotaur,&Theseus,&step);
		Theseus-='A',Minotaur-='A';
		for(i=1;;i++){
			min=26;
			for(j=0;j<26;j++)
				if(map[Minotaur][j]&&!candle[j]&&Theseus!=j)
					if(min>map[Minotaur][j]) min=map[Minotaur][j],nextmove=j;
			if(min==26){
				printf("/%c\n",Minotaur+'A');
				break;
			}
			Theseus=Minotaur,Minotaur=nextmove;
			if(i%step==0) printf("%c ",Theseus+'A'),candle[Theseus]=1;
		}
	}
	return 0;
}
