#include<stdio.h>
#include<string.h>
int main(){
	int cases,D,P,H,i,count;
	char days[3660];
	scanf("%d",&cases);
	while(cases--){
		memset(days,0,sizeof(days));
		scanf("%d",&D);
		scanf("%d",&P);
		while(P--){
			scanf("%d",&H);
			for(i=H;i<=D;i+=H)
				if(i%7!=0&&i%7!=6)
					days[i]=1;
		}
		count=0;
		for(i=1;i<=D;i++)
			if(days[i]) count++;
		printf("%d\n",count);
	}
	return 0;
}
