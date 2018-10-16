#include<stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
int main(){
	int table[45][45]={{0}};
	int i,j,k,a1,an;
	for(i=0;i<44;i++){
		table[i][i]=1;
		for(j=i+1;j<45;j++){
			for(k=1;k<=MIN(j/2,j-i);k++)
				if(j%k==0)
					table[i][j]+=table[i][j-k];
			if(i==0) table[i][j]++;
		}
	}
	while(scanf("%d%d",&a1,&an),a1|an)
		printf("%d %d %d\n",a1,an,table[a1][an]);
	return 0;
}
