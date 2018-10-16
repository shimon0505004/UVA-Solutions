#include<stdio.h>
void print_base_i_minus_1(int a,int b){
	int na=a-b,nb=a+b;
	char flag=0;
	if(na&1) --na,--nb,flag=1;
	na/=-2,nb/=-2;
	if(na!=0||nb!=0) print_base_i_minus_1(na,nb);
	if(flag) putchar('1');
	else putchar('0');
}
int main(){
	int cases,T;
	int a,b;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d",&a,&b);
		printf("Case #%d: ",cases);
		print_base_i_minus_1(a,b);
		puts("");
	}
	return 0;
}
