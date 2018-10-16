#include<stdio.h>
#include<string.h>
int main(){
	char n1[105],n2[105],res[105];
	int i,d;
	char flag,start=0,*ptr;
	while(scanf("%s%s",n1,n2)==2){
		int len1=strlen(n1),len2=strlen(n2);
		if(start) puts("");
		start=1;
		memmove(n1+104-len1,n1,sizeof(char[len1+1]));
		memmove(n2+104-len2,n2,sizeof(char[len2+1]));
		memset(n1,'0',sizeof(char[104-len1]));
		memset(n2,'0',sizeof(char[104-len2]));
		memset(res,0,sizeof(res));
		for(i=0;i<104;i++) res[i]=n1[i]+n2[i]-'0';
		do{
			flag=0;
			if(res[103]>'1'){
				d=(res[103]-'0')/2;
				res[103]-=2*d,res[102]+=d,flag=1;
			}
			if(res[102]>'1'){
				d=(res[102]-'0')/2;
				res[102]-=2*d,res[101]+=d,res[103]+=d,flag=1;
			}
			for(i=101;i>0;i--){
				if(res[i]>'1'){
					d=(res[i]-'0')/2;
					flag=1,res[i+2]+=d,res[i-1]+=d;
					res[i]-=2*d;
				}
				if(res[i+2]>'0'&&res[i+1]>'0'){
					d=res[i+2]>res[i+1]?res[i+1]-'0':res[i+2]-'0';
					res[i]+=d,flag=1;
					res[i+2]-=d,res[i+1]-=d;
				}
			}
		}while(flag==1);
		if((ptr=strchr(res,'1'))==NULL) puts("0");
		else puts(ptr);
	}
	return 0;
}
