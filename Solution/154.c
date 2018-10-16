#include<stdio.h>
#include<string.h>
int main(){
	int bin[5][5],len,count,i,j;
	int city[105][5],score[105],max,TheOne;
	char map[128];
	char input[25],*ptr,color,wastes;
	map['r']=0,map['o']=1,map['y']=2,map['g']=3,map['b']=4;
	map['P']=0,map['G']=1,map['S']=2,map['A']=3,map['N']=4;
	for(;;){
		memset(bin,0,sizeof(bin));
		memset(city,0,sizeof(city));
		memset(score,0,sizeof(score));
		for(count=0;fgets(input,25,stdin)!=NULL;count++){
			if(*input=='#'||*input=='e') break;
			for(ptr=input;sscanf(ptr,"%c%*c%c%*c%n",&color,&wastes,&len)==2;ptr+=len){
				city[count][map[color]]=map[wastes];
				bin[map[color]][map[wastes]]++;
			}
		}
		if(*input=='#') break;
		max=0;
		for(i=0;i<count;i++){
			for(j=0;j<5;j++)
				score[i]+=bin[j][city[i][j]];
			if(score[i]>max) max=score[i],TheOne=i;
		}
		printf("%d\n",TheOne+1);
	}
	return 0;
}
