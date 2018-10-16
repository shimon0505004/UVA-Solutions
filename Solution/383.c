#include<stdio.h>
#include<string.h>
#define INF 100000
int convert(char *s){
	return (s[0]-'A')*26+s[1]-'A';
}
int main(){
	int map[700][700];
	int cases,T,WH,Legs,R;
	int WareHouse[40],i,j,k,t,unit;
	char name1[5],name2[5];
	scanf("%d",&T);
	puts("SHIPPING ROUTES OUTPUT\n");
	for(cases=1;cases<=T;cases++){
		printf("DATA SET  %d\n\n",cases);
		scanf("%d%d%d",&WH,&Legs,&R);
		for(i=0;i<WH;i++){
			scanf("%s",name1);
			WareHouse[i]=convert(name1);
		}
		for(i=0;i<WH;i++)
			for(j=0;j<WH;j++)
				map[WareHouse[i]][WareHouse[j]]=INF;
		while(Legs--){
			int w1,w2;
			scanf("%s%s",name1,name2);
			w1=convert(name1),w2=convert(name2);
			map[w1][w2]=map[w2][w1]=1;
		}
		for(k=0;k<WH;k++)
			for(i=0;i<WH;i++)
				for(j=0;j<i;j++){
					int w1=WareHouse[i],w2=WareHouse[j],w3=WareHouse[k];
					if((t=map[w1][w3]+map[w3][w2])<map[w1][w2])
						map[w1][w2]=map[w2][w1]=t;
				}
		for(i=0;i<R;i++){
			scanf("%d%s%s",&unit,name1,name2);
			if((t=map[convert(name1)][convert(name2)])==INF)
				puts("NO SHIPMENT POSSIBLE");
			else printf("$%d\n",100*t*unit);
		}
		puts("");
	}
	puts("END OF OUTPUT");
	return 0;
}
