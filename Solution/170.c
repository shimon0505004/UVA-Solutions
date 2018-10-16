#include<stdio.h>
#include<string.h>
char stack[13][4][3];
char result[3];
int n_stack[13];
void push(char *k,int n)
{
	strcpy(stack[n][--n_stack[n]],k);
}
void pop(int n)
{
	strcpy(result,stack[n][--n_stack[n]]);
}
int is_empty(int n)
{
	return !n_stack[n];
}
int main()
{
	int i,j,count;
	char temp[3];
	const char *face="A23456789TJQK";
	while(1){
		for(i=0;i<13;i++)
			n_stack[i]=4;
		for(i=0;i<4;i++)
			for(j=12;j>=0;j--){
				scanf("%s",temp);
				if(*temp=='#') return 0;
				push(temp,j);
			}
		for(i=0;i<13;i++)
			n_stack[i]=4;
		i=12;
		for(count=0;!is_empty(i);count++){
			pop(i);
			i=strchr(face,*result)-face;
		}
		printf("%.2d,%s\n",count,result);
	}
	return 0;
}
