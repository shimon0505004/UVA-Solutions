#include<stdio.h>
unsigned getHex(int n){
	unsigned res=0,t;
	int i;
	for(i=0;i<n;i++){
		scanf("%1X ",&t);
		res=(res<<4)+t;
	}
	return res;
}
void printArg(unsigned arg){
	unsigned type=arg>>14;
	if(type==0) printf("R");
	else if(type==1) printf("$");
	else if(type==2) printf("PC+");
	printf("%u",arg&0x3FFF);
}
int main(){
	char *instr_name[16]={
		"ADD","SUB","MUL","DIV","MOV","BREQ","BRLE","BRLS",
		"BRGE","BRGR","BRNE","BR","AND","OR","XOR","NOT"};
	unsigned instr;
	while(!feof(stdin)){
		instr=getHex(1);
		printf("%s ",instr_name[instr]);
		if(instr<0x5){
			unsigned arg1=getHex(4),arg2=getHex(4);
			printArg(arg1),putchar(','),printArg(arg2);
		}else if(instr<0xC){
			unsigned arg=getHex(4);
			printArg(arg);
		}else if(instr<0xF){
			unsigned arg1=getHex(4),arg2=getHex(4),arg3=getHex(4);
			printArg(arg1);
			putchar(','),printArg(arg2);
			putchar(','),printArg(arg3);
		}else{
			unsigned arg=getHex(4);
			printArg(arg);
		}
		puts("");
	}
	return 0;
}
