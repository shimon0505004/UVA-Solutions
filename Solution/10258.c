#include<stdio.h>
struct contestant{
	int correcttime[10];
	int WAs[10];
	int solved;
	int penalty;
};
int main()
{
	struct contestant C[105];
	int cases;
	char input[20];
	int n,p,t,i,j;
	char present[105];
	int max,maxn;
	scanf("%d ",&cases);
	while(cases--){
		memset(present,0,sizeof(present));
		for(i=0;i<105;i++){
			memset(C[i].correcttime,0,sizeof(C[i].correcttime));
			memset(C[i].WAs,0,sizeof(C[i].WAs));
			C[i].solved=0;
			C[i].penalty=0;
		}
		while(fgets(input,20,stdin)!=NULL){
			if(*input=='\n') break;
			sscanf(input,"%d%d%d %c",&n,&p,&t,&j);
			present[n]=1;
			switch(j){
				case 'C':
					if(!C[n].correcttime[p]){
						C[n].correcttime[p]=t;
						C[n].solved++;
						C[n].penalty+=t+C[n].WAs[p]*20;
					}
					break;
				case 'I':
					if(!C[n].correcttime[p])
						C[n].WAs[p]++;
					break;
			}
		}
		do{
			max=-1;
			maxn=0;
			for(i=0;i<105;i++){
				if(!present[i]) continue;
				if(C[i].solved>max){
					max=C[i].solved;
					maxn=i;
				}
			}
			if(maxn)
				printf("%d %d %d\n",maxn,max,C[maxn].penalty);
			C[maxn].solved=0;
			present[maxn]=0;
		}while(maxn);
		if(cases) printf("\n");
	}
	return 0;
}
