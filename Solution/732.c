#include<stdio.h>
#include<string.h>
char stack[1005];
int n_stack;
void push(char c){
	stack[n_stack++]=c;
}
char pop(){
	return stack[--n_stack];
}
char top(){
	return stack[n_stack-1];
}
char is_empty(){
	return n_stack==0;
}
char src[1005],dest[1005];
int len;
char ans[2005];
void dfs(int pushed,int popped,int depth){
	int i;
	if(popped==len){
		putchar(ans[0]);
		for(i=1;i<depth;i++) printf(" %c",ans[i]);
		puts("");
		return;
	}
	if(pushed<len){
		ans[depth]='i';
		push(src[pushed]);
		dfs(pushed+1,popped,depth+1);
		pop();
	}
	if(!is_empty()&&top()==dest[popped]){
		char c=pop();
		ans[depth]='o';
		dfs(pushed,popped+1,depth+1);
		push(c);
	}
}
int main(){
	int v1[128],v2[128],len1,len2;
	int i;
	while(scanf("%s%s",src,dest)==2){
		len1=strlen(src),len2=strlen(dest);
		memset(v1,0,sizeof(v1)),memset(v2,0,sizeof(v2));
		if((len=len1)==len2)
			for(i=0;i<len1;i++)
				v1[(int)src[i]]++,v2[(int)dest[i]]++;
		puts("[");
		if(len1==len2&&memcmp(v1,v2,sizeof(int[128]))==0){
			n_stack=0;
			memset(ans,0,sizeof(ans));
			dfs(0,0,0);
		}
		puts("]");
	}
	return 0;
}
