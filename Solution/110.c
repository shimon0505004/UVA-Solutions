#include<stdio.h>
int n;
void dfs(int depth,char output[]){
	char temp[10],c='a'+depth;
	char space[20]="                   ";
	int i,j;
	space[depth<<1]=0;
	if(depth==n){
		printf(space);
		printf("writeln(");
		putchar(*output);
		for(i=1;i<n;i++)
			printf(",%c",output[i]);
		puts(")");
		return;
	}
	printf("%sif %c < %c then\n",space,output[depth-1],c);
	for(i=0;i<depth;i++)
		temp[i]=output[i];
	temp[depth]=c;
	dfs(depth+1,temp);
	for(i=depth-2;i>=0;i--){
		printf(space);
		printf("%selse if %c < %c then\n",space,output[i],c);
		for(j=0;j<=i;j++)
			temp[j]=output[j];
		temp[i+1]=c;
		for(j=i+2;j<=depth;j++)
			temp[j]=output[j-1];
		dfs(depth+1,temp);
	}
	printf(space);
	puts("else");
	temp[0]=c;
	for(i=1;i<=depth;i++)
		temp[i]=output[i-1];
	dfs(depth+1,temp);
	return;
}
int main(){
	int cases,i;
	char metaloop[10];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		puts("program sort(input,output);");
		puts("var");
		putchar('a');
		for(i=1;i<n;i++)
			printf(",%c",'a'+i);
		puts(" : integer;");
		puts("begin");
		printf("  readln(a");
		for(i=1;i<n;i++)
			printf(",%c",'a'+i);
		puts(");");
		metaloop[0]='a';
		dfs(1,metaloop);
		puts("end.");
		if(cases) puts("");
	}
	return 0;
}
