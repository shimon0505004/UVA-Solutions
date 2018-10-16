#include<stdio.h>
#include<string.h>
struct CAR{
	int length;
	char direc;
};
int main(){
	int cases,ferry;
	int n;
	struct CAR car[205];
	int table[205][10005];
	int i,j,tmp;
	int length;
	int sum,total;
	scanf("%d",&cases);
	while(cases--){
		total=0;
		scanf("%d",&ferry);
		ferry*=100;
		n=0;
		memset(car,0,sizeof(car));
		while(scanf("%d",&tmp),tmp)
			if(total+tmp<=ferry*2) car[++n].length=tmp,total+=tmp;
			else break;
		if(tmp!=0) while(scanf("%d",&tmp),tmp);
		memset(table,0,sizeof(table));
		for(i=1;i<=n;i++){
			for(j=1;j<=ferry;j++){
				if(car[i].length>j)
					table[i][j]=table[i-1][j];
				else{
					if(table[i-1][j]<car[i].length+table[i-1][j-car[i].length])
						table[i][j]=car[i].length+table[i-1][j-car[i].length];
					else table[i][j]=table[i-1][j];
				}
			}
		}
		for(;n>0;n--){
			for(i=1;i<=n;i++) car[i].direc=0;
			length=table[n][ferry];
			for(i=n,sum=0;i>0;i--){
				if(car[i].length>length) continue;
				if(table[i][length]==table[i-1][length-car[i].length]+car[i].length){
					car[i].direc=1;
					sum+=car[i].length;
					length-=car[i].length;
				}
			}
			if(total-sum<=ferry) break;
			total-=car[n].length;
		}
		printf("%d\n",n);
		for(i=1;i<=n;i++)
			if(car[i].direc) puts("port");
			else puts("starboard");
		if(cases) puts("");
	}
	return 0;
}
