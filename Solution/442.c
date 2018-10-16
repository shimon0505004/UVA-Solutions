#include<stdio.h>
#include<string.h>
#define SIZE 100
typedef struct MATRIX{
	int row,col;
}Matrix;
int n_stack;
int p_stack;
char parentheses[SIZE];
Matrix stack[SIZE];
void push_p(char c){
	parentheses[p_stack++]=c;
}
void pop_p(){
	--p_stack;
}
char p_is_empty(){
	return p_stack==0;
}
Matrix pop_n(){
	return stack[--n_stack];
}
void push_n(Matrix m){
	stack[n_stack++]=m;
}
char n_is_empty(){
	return n_stack==0;
}
int main(){
	int n,i,len,multiplications;
	char c,input[SIZE];
	Matrix m[26],a,b;
	scanf("%d ",&n);
	for(i=0;i<n;i++){
		c=getchar();
		scanf("%d%d ",&m[c-'A'].row,&m[c-'A'].col);
	}
	while(fgets(input,100,stdin)!=NULL){
		len=strlen(input);
		n_stack=p_stack=multiplications=0;
		for(i=0;i<len-1;i++){
			if(input[i]=='(') push_p('(');
			else if(input[i]==')'){
				a=pop_n(),b=pop_n();
				pop_p();
				if(b.col!=a.row) break;
				multiplications+=b.row*b.col*a.col;
				b.col=a.col;
				push_n(b);
			}else
				push_n(m[input[i]-'A']);
		}
		if(i==len-1) printf("%d\n",multiplications);
		else puts("error");
	}
	return 0;
}
