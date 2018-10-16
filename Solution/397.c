#include<stdio.h>
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define EQUAL 5
char is_operator[128]={0};
struct OPER{
	char operator;
	int operand;
	char visit;
};
char *getOper(struct OPER *op,char *ptr){
	int len;
	while(!is_operator[(int)*++ptr]);
	if(is_operator[(int)*ptr]==EQUAL) return ptr;
	op->operator=is_operator[(int)*ptr++];
	sscanf(ptr,"%d%n",&(op->operand),&len);
	return ptr+len-1;
}
char operator(char flag){
	if(flag==ADD) return '+';
	if(flag==SUBTRACT) return '-';
	if(flag==MULTIPLY) return '*';
	if(flag==DIVIDE) return '/';
	return '#';
}
void printEquation(int n_oper,struct OPER *op,char variable[]){
	int i;
	for(i=0;op[i].visit==1&&i<n_oper;i++);
	printf("%d ",op[i].operand);
	for(i++;i<n_oper;i++)
		if(op[i].visit==0)
			printf("%c %d ",operator(op[i].operator),op[i].operand);
	printf("= %s\n",variable);
}
char reduce(int n_oper,struct OPER *op){
	int i;
	int cal_from,cal_to;
	cal_from=0;
	for(i=1;i<n_oper;i++){
		if(op[i].visit==0){
			if(op[i].operator==MULTIPLY||op[i].operator==DIVIDE){
				cal_to=i;
				break;
			}
			cal_from=i;
		}
	}
	if(i==n_oper){
		cal_from=0;
		for(i=1;i<n_oper;i++){
			if(op[i].visit==0){
				cal_to=i;
				break;
			}
		}
	}
	if(i==n_oper) return 0;
	op[cal_to].visit=1;
	if(op[cal_to].operator==ADD)
		op[cal_from].operand+=op[cal_to].operand;
	else if(op[cal_to].operator==SUBTRACT)
		op[cal_from].operand-=op[cal_to].operand;
	else if(op[cal_to].operator==MULTIPLY)
		op[cal_from].operand*=op[cal_to].operand;
	else if(op[cal_to].operator==DIVIDE)
		op[cal_from].operand/=op[cal_to].operand;
	return 1;
}
int main(){
	struct OPER oper[25];
	char variable[10];
	char line[300],*ptr;
	int n_oper;
	is_operator['+']=ADD,is_operator['-']=SUBTRACT,is_operator['*']=MULTIPLY,is_operator['/']=DIVIDE,is_operator['=']=EQUAL;
	while(fgets(line+1,300,stdin)!=NULL){
		line[0]='+';
		for(n_oper=0,ptr=line-1;ptr=getOper(&oper[n_oper],ptr),*ptr!='=';n_oper++)
			oper[n_oper].visit=0;
		sscanf(ptr+1,"%s",variable);
		printEquation(n_oper,oper,variable);
		while(reduce(n_oper,oper))
			printEquation(n_oper,oper,variable);
		puts("");
	}
	return 0;
}
