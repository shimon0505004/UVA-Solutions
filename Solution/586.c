#include<stdio.h>
#include<string.h>
struct POLY{
	int coef[11];
};
void getStatement(struct POLY *poly){
	char operator[10],operand[10];
	int cnt;
	int i;
	memset(poly,0,sizeof(struct POLY));
	while(scanf("%s",operator),strcmp(operator,"END")){
		if(strcmp(operator,"LOOP")==0){
			struct POLY tmp;
			scanf("%s",operand);
			getStatement(&tmp);
			if(strcmp(operand,"n")==0){
				memmove(tmp.coef+1,tmp.coef,sizeof(int[10]));
				tmp.coef[0]=0;
			}else{
				sscanf(operand,"%d",&cnt);
				for(i=0;i<11;i++) tmp.coef[i]*=cnt;
			}
			for(i=0;i<11;i++) poly->coef[i]+=tmp.coef[i];
		}else if(strcmp(operator,"OP")==0){
			scanf("%d",&cnt);
			poly->coef[0]+=cnt;
		}
	}
}
void printPoly(struct POLY *poly){
	int i;
	printf("Runtime = ");
	for(i=10;i>0&&poly->coef[i]==0;i--);
	if(i==0) printf("%d",poly->coef[0]);
	else if(i==1){
		if(poly->coef[1]!=1) printf("%d*",poly->coef[1]);
		printf("n");
		if(poly->coef[0]!=0) printf("%+d",poly->coef[0]);
	}else{
		if(poly->coef[i]!=1) printf("%d*",poly->coef[i]);
		printf("n^%d",i);
		for(i--;i>1;i--)
			if(poly->coef[i]!=0){
				if(poly->coef[i]!=1) printf("%+d*",poly->coef[i]);
				else putchar('+');
				printf("n^%d",i);
			}
		if(poly->coef[1]!=0){
			if(poly->coef[1]!=1) printf("%+d*",poly->coef[1]);
			else putchar('+');
			printf("n");
		}
		if(poly->coef[0]!=0) printf("%+d",poly->coef[0]);
	}
	puts("");
}
int main(){
	int T,cases;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		struct POLY poly;
		printf("Program #%d\n",cases);
		scanf("%*s");
		getStatement(&poly);
		printPoly(&poly);
		puts("");
	}
	return 0;
}
