#include<stdio.h>
#include<string.h>
int main(){
	int n,i,y,a,b,j,cases;
	char y_possible[10005];
	for(cases=1;scanf("%d",&n),n;cases++){
		memset(y_possible,0,sizeof(y_possible));
		for(i=0;i<n;i++){
			int diff;
			scanf("%d%d%d",&y,&a,&b);
			diff=b-a;
			for(j=y;j<10000;j+=diff)
				y_possible[j]++;
		}
		for(i=0;i<10000;i++)
			if(y_possible[i]==n) break;
		printf("Case #%d:\n",cases);
		if(i<10000) printf("The actual year is %d.\n",i);
		else puts("Unknown bugs detected.");
		puts("");
	}
	return 0;
}
