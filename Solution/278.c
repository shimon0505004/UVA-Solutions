#include<stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int cases;
	char piece;
	int m,n,queens[4]={0,1,1,2},min;
	scanf("%d ",&cases);
	while(cases--){
		scanf("%c%d%d ",&piece,&m,&n);
		if(piece=='r') printf("%d\n",MIN(m,n));
		else if(piece=='k') printf("%d\n",(m*n+1)>>1);
		else if(piece=='K') printf("%d\n",((m+1)>>1)*((n+1)>>1));
		else{
			min=MIN(m,n);
			if(min<4) printf("%d\n",queens[min]);
			else printf("%d\n",min);
		}
	}
	return 0;
}
