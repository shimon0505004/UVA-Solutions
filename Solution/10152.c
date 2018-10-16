#include<stdio.h>
#include<string.h>
int findNO(char sorted[][85],char find[]){
	int n;
	for(n=0;strcmp(sorted[n],find)!=0;n++);
	return n;
}
int stack[205];
int n_stack;
void push(int n){
	stack[n_stack++]=n;
}
int pop(){
	return stack[--n_stack];
}
void delete(int find,int turtle[],int n){
	int i;
	for(i=find;i<n;i++)
		if(turtle[i]==find)
			memmove(turtle+1,turtle,sizeof(int[i]));
}
int main(){
	int cases;
	int n,i,j;
	int turtle[205];
	char name[205][85];
	char sorted[205][85];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d ",&n);
		for(i=0;i<n;i++) fgets(name[i],85,stdin);
		for(i=0;i<n;i++) fgets(sorted[i],85,stdin);
		for(i=0;i<n;i++) turtle[i]=findNO(sorted,name[i]);
		n_stack=0;
		for(i=0;i<n;i++){
			if(turtle[i]!=i) push(i),delete(i,turtle,n);
			else{
				delete(i,turtle,n);
				for(j=i+1;j<n;j++)
					if(turtle[j]!=j)
						break;
				if(j<n) push(i);
			}
		}
		while(n_stack>0)
			printf(sorted[pop()]);
		puts("");
	}
	return 0;
}
