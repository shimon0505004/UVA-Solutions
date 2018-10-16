#include<stdio.h>
int main(){
	int n,m,i,j;
	char STree[130],x[3];
	char VVA[10];
	int seq[10],cases,offset;
	for(cases=1;scanf("%d",&n),n;cases++){
		printf("S-Tree #%d:\n",cases);
		for(i=0;i<n;i++) scanf("%s ",x),seq[x[1]-'1']=n-i-1;
		fgets(STree,130,stdin);
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%s",VVA);
			for(j=offset=0;j<n;j++)
				if(VVA[j]=='1')
					offset+=1<<seq[j];
			putchar(STree[offset]);
		}
		puts("\n");
	}
	return 0;
}
