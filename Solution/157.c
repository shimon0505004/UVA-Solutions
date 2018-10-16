#include<stdio.h>
#include<string.h>
int relay[676][676];
void printRoute(int from,int to){
	int r=relay[from][to];
	if(r!=-1){
		printRoute(from,r);
		printRoute(r,to);
	}else{
		if(from/26!=to/26) printf("=%c%c",to/26+'A',to%26+'a');
		else putchar(to%26+'a');
	}
}
int main(){
	int routes;
	char r,line[100];
	int map[676][676];
	int i,j,k,t,len,from,to;
	scanf("%d ",&routes);
	for(i=0;i<676;i++)
		for(j=0;j<676;j++)
			map[i][j]=1000000000,relay[i][j]=-1;
	while(routes--){
		scanf("%c%*c%s ",&r,line);
		r-='A';
		len=strlen(line);
		from=r*26+line[0]-'a';
		for(i=1;i<len;i++){
			if(line[i]=='='){
				to=(line[i+1]-'A')*26+line[i+2]-'a';
				map[from][to]=map[to][from]=3;
				i+=2;
			}else{
				to=r*26+line[i]-'a';
				map[from][to]=map[to][from]=1;
				from=to;
			}
		}
	}
	for(k=0;k<676;k++)
		for(i=0;i<676;i++)
			for(j=0;j<i;j++)
				if(map[i][k]==3&&map[k][j]==3) map[i][j]=map[j][i]=3;
	for(k=0;k<676;k++)
		for(i=0;i<676;i++)
			for(j=0;j<i;j++)
				if((t=map[i][k]+map[k][j])<map[i][j]){
					map[i][j]=map[j][i]=t;
					relay[i][j]=relay[j][i]=k;
				}
	while(fgets(line,100,stdin),*line!='#'){
		from=(line[0]-'A')*26+line[1]-'a';
		to=(line[2]-'A')*26+line[3]-'a';
		printf("%3d: ",map[from][to]);
		printf("%c%c",line[0],line[1]);
		printRoute(from,to);
		puts("");
	}
	return 0;
}
