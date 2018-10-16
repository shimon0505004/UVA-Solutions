#include<stdio.h>
#include<string.h>
int main(){
	int cases,cands,i,len,count,max,maxi,min;
	char names[25][85];
	char input[70],*ptr;
	int Ballots[1005][25],b;
	int counter[1005],vote[25];
	char eliminated[25];
	scanf("%d",&cases);
	while(cases--){
		memset(Ballots,0,sizeof(Ballots));
		memset(counter,0,sizeof(counter));
		memset(vote,0,sizeof(vote));
		memset(eliminated,0,sizeof(eliminated));
		scanf("%d ",&cands);
		for(i=1;i<=cands;i++) fgets(names[i],85,stdin);
		for(count=0;fgets(input,70,stdin);count++){
			if(*input=='\n') break;
			for(i=0,ptr=input;i<cands;i++,ptr+=len)
				sscanf(ptr,"%d%n",&Ballots[count][i],&len);
		}
		for(i=0;i<count;i++)
			vote[Ballots[i][counter[i]]]++;
		for(;;){
			max=0,min=count;
			for(i=1;i<=cands;i++){
				if(vote[i]>max) max=vote[i],maxi=i;
				if(vote[i]<min&&vote[i]>0) min=vote[i];
			}
			if(max<=min){
				for(i=1;i<=cands;i++)
					if(vote[i]==max)
						printf(names[i]);
				break;
			}else if(max>count/2){
				printf(names[maxi]);
				break;
			}else{
				for(i=1;i<=cands;i++)
					if(vote[i]==min||vote[i]==0) eliminated[i]=1,vote[i]=0;
				for(i=0;i<count;i++)
					while(eliminated[Ballots[i][counter[i]]])
						vote[Ballots[i][++counter[i]]]++;
			}
		}
		if(cases) puts("");
	}
	return 0;
}
