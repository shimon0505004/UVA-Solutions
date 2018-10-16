#include<stdio.h>
#include<string.h>
void reverse(char s[]){
	int len=strlen(s);
	int i;
	char temp;
	for(i=0;i<len/2;i++)
		temp=s[i],s[i]=s[len-i-1],s[len-i-1]=temp;
}
void multiply(char des[],char src[],int len){
	int i,j;
	int temp[150]={0};
	for(i=0;i<5;i++)
		for(j=0;j<len;j++)
			temp[i+j]+=(src[i]-'0')*(des[j]-'0');
	for(i=0;i<len+5;i++){
		temp[i+1]+=temp[i]/10;
		temp[i]=temp[i]%10+'0';
	}
	for(i=0;i<len+5;i++) des[i]=temp[i];
}
int main(){
	char R[10],R_n[150],*ptr;
	int n,dap,i;
	while(scanf("%s%d",R,&n)==2){
		if((ptr=strchr(R,'.'))!=NULL){
			dap=5-(ptr-R);
			memmove(ptr,ptr+1,sizeof(char[dap+1]));
		}else dap=0;
		reverse(R);
		memset(R_n,'0',sizeof(R_n));
		strncpy(R_n,R,5);
		for(i=1;i<n;i++)
			multiply(R_n,R,i*5);
		memmove(R_n+n*dap,R_n+n*dap-1,149-n*dap);
		R_n[n*dap]='.';
		for(i=0;i<n*dap&&R_n[i]=='0';i++);
		if(i>0) R_n[i-1]=0,ptr=R_n+i;
		else ptr=R_n;
		for(i=149;R_n[i]=='0';i--);
		R_n[i+1]=0;
		reverse(ptr);
		puts(ptr);
	}
	return 0;
}
