#include<stdio.h>
#include<string.h>
#define MAXD 110
#define N_FIB 500
void assign(char dest[],char src[]){
	memcpy(dest,src,sizeof(char[MAXD]));
}
void add(char dest[],char src[]){
	int i;
	for(i=0;i<MAXD;i++)
		dest[i]+=src[i];
	for(i=1;i<MAXD;i++)
		dest[i]+=dest[i-1]/10,dest[i-1]%=10;
}
void printFib(char fib[]){
	int i;
	for(i=MAXD-1;fib[i]==0&&i>=0;i--);
	printf("%d digits: ",i+1);
	for(;i>=0;i--) printf("%d",fib[i]);
	puts("");
}
int compar(char a[],char b[]){
	int i;
	for(i=MAXD-1;i>=0;i--)
		if(a[i]!=b[i])
			return a[i]-b[i];
	return 0;
}
void convert(char fib[]){
	char temp;
	int len=strlen(fib),h_len=len/2;
	int i;
	for(i=0;i<len;i++) fib[i]-='0';
	for(i=0;i<h_len;i++)
		temp=fib[i],fib[i]=fib[len-i-1],fib[len-i-1]=temp;
	for(i=len;i<MAXD;i++) fib[i]=0;
}
int main(){
	char fib[N_FIB][MAXD]={{0}};
	char a[MAXD],b[MAXD];
	int i,U,L;
	fib[0][0]=1,fib[1][0]=1;
	for(i=2;i<N_FIB;i++){
		assign(fib[i],fib[i-1]);
		add(fib[i],fib[i-2]);
	}
	while(scanf("%s%s",a,b),strcmp(a,"0")!=0||strcmp(b,"0")!=0){
		convert(a),convert(b);
		for(L=1;compar(a,fib[L])>0;L++);
		for(U=N_FIB-1;compar(b,fib[U])<0;U--);
		printf("%d\n",U-L+1);
	}
	return 0;
}
