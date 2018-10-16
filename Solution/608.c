#include<stdio.h>
#include<string.h>
#define IMPOSSIBLE -1
#define UNKNOWN 0
#define LIGHT 1
#define HEAVY 2
int main(){
	int cases,i,j,len;
	char coin[12];
	char left[10],right[10],balance[10];
	scanf("%d",&cases);
	while(cases--){
		memset(coin,0,sizeof(coin));
		for(i=0;i<3;i++){
			scanf("%s%s%s",left,right,balance);
			len=strlen(left);
			if(*balance=='e')
				for(j=0;j<len;j++) coin[left[j]-'A']=IMPOSSIBLE,coin[right[j]-'A']=IMPOSSIBLE;
			else if(*balance=='u')
				for(j=0;j<12;j++){
					if(strchr(left,'A'+j)!=NULL){
						if(coin[j]==UNKNOWN) coin[j]=HEAVY;
						else if(coin[j]==LIGHT) coin[j]=IMPOSSIBLE;
					}else if(strchr(right,'A'+j)!=NULL){
						if(coin[j]==UNKNOWN) coin[j]=LIGHT;
						else if(coin[j]==HEAVY) coin[j]=IMPOSSIBLE;
					}else if(coin[j]!=UNKNOWN) coin[j]=IMPOSSIBLE;
				}
			else
				for(j=0;j<12;j++){
					if(strchr(left,'A'+j)!=NULL){
						if(coin[j]==UNKNOWN) coin[j]=LIGHT;
						else if(coin[j]==HEAVY) coin[j]=IMPOSSIBLE;
					}else if(strchr(right,'A'+j)!=NULL){
						if(coin[j]==UNKNOWN) coin[j]=HEAVY;
						else if(coin[j]==LIGHT) coin[j]=IMPOSSIBLE;
					}else if(coin[j]!=UNKNOWN) coin[j]=IMPOSSIBLE;
				}
		}
		for(i=0;i<12;i++){
			if(coin[i]==LIGHT){
				printf("%c is the counterfeit coin and it is light.\n",i+'A');
				break;
			}else if(coin[i]==HEAVY){
				printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
				break;
			}
		}
	}
	return 0;
}
